#include <QtGui>

#include "mainWindow.h"
#include "tripImportDialog.h"
#include "tankImportDialog.h"
#include "multiTripImportDialog.h"

#define SECS_PER_MIN 60
#define SECS_PER_HOUR 3600

MainWindow::MainWindow()
{
    setupUi(this);

    connect(actionImport_Trip, SIGNAL(activated()), this, SLOT(openTripImportDialog()));
    connect(actionImport_Tank, SIGNAL(activated()), this, SLOT(openTankImportDialog()));
    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(dateClicked(QDate)));
    connect(actionExit, SIGNAL(activated()), this, SLOT(close()));
    connect(actionImport_multiTrips, SIGNAL(activated()), this, SLOT(openMultiTripImportDialog()));

    connect(timeType, SIGNAL(currentIndexChanged(int)), this, SLOT(timeTypeChanged(int)));
    connect(speedType, SIGNAL(currentIndexChanged(int)), this, SLOT(speedTypeChanged(int)));
}


void MainWindow::openTripImportDialog()
{
    TripImportDialog *tripimportDialog = new TripImportDialog(this);
    tripimportDialog->show();
}


void MainWindow::openTankImportDialog()
{
    TankImportDialog *tankImportDialog = new TankImportDialog(this);
    tankImportDialog->show();
}


void MainWindow::openMultiTripImportDialog()
{
    MultiTripImportDialog *multiTripImportDialog = new MultiTripImportDialog(this);
    multiTripImportDialog->show();
}


void MainWindow::dateClicked(QDate date)
{
    QList<Trip> trips = Database::getInstance()->getAllTrips(date);
    QList<Tank> tanks = Database::getInstance()->getAllTanks(date);
    int time = timeType->currentIndex();
    int speed = speedType->currentIndex();

    fillOverviewList(trips, tanks);
    fillTable(trips);
    paintGraph(time, speed, date);

}


void MainWindow::fillOverviewList(const QList<Trip> &trips, const QList<Tank> &tanks)
{
    tripViews->clear();

   for(int i = 0; i < trips.size(); i++)
    {
        tripViews->addItem(new QListWidgetItem("Trip:   " + trips.at(i).getStartDate().toString("yyyy-MM-dd") + "." + QString::number(i)));
    }

   for(int i = 0; i < tanks.size(); i++)
   {
       tripViews->addItem(new QListWidgetItem("Tank: " + tanks.at(i).getDate().toString("yyyy-MM-dd") + "." + QString::number(i)));
   }

   if(tripViews->count() == 0)
   {
       tripViews->addItem(new QListWidgetItem(QString("--- None ---")));
   }
}


void MainWindow::fillTable(const QList<Trip> &trips)
{
    QStringList HorizontalLabels;
    HorizontalLabels << tr("startDate") << tr("EndDate") << tr("Duration") << tr("Distance") << tr("average Speed") << tr("Maximum speed");
    tableWidget->hide();
    tableWidget->clearContents();
    tableWidget->setRowCount(trips.size());
    tableWidget->setColumnCount(HorizontalLabels.size());
    tableWidget->setHorizontalHeaderLabels(HorizontalLabels);
    tableWidget->setShowGrid(true);

    for(int i = 0; i < trips.size(); i++)
    {
        tableWidget->setItem(i, 0, new QTableWidgetItem(trips.at(i).getStartDate().toString("yyyy-MM-dd h:mm AP")));
        tableWidget->setItem(i, 1, new QTableWidgetItem(trips.at(i).getStopDate().toString("yyyy-MM-dd h:mm AP")));
        tableWidget->setItem(i, 2, new QTableWidgetItem(durationToString(trips.at(i).getDuration())));
        tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(trips.at(i).getDistance() * 0.001) + " Kilometers"));
        tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(trips.at(i).getAvgSpeed()) + " KM/H"));
        tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(trips.at(i).getMaxSpeed()) + " KM/H"));
    }

    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    tableWidget->show();
}


QString MainWindow::durationToString(int duration) const
{
    unsigned minutes, hours, secs_left, mins_left;

    // Do the modulus operations
    hours = duration / SECS_PER_HOUR;
    minutes = duration / SECS_PER_MIN;
    mins_left = minutes % SECS_PER_MIN;
    secs_left = duration % SECS_PER_MIN;

    QString durationStr;
    durationStr = QString("%1h:%2m:%3s").arg(hours).arg(mins_left).arg(secs_left);
    return durationStr;

}


void MainWindow::speedTypeChanged(int index)
{
    int time = timeType->currentIndex();
    QDate date = calendarWidget->selectedDate();

    paintGraph(time, index, date);
}


void MainWindow::timeTypeChanged(int index)
{
    int speed = speedType->currentIndex();
    QDate date = calendarWidget->selectedDate();

    paintGraph(index, speed, date);
}


void MainWindow::paintGraph(int timeIndex, int speedIndex, const QDate &date)
{
    setupPlotArea();

    QList<Trip> trips = Database::getInstance()->getAllTripsLocations(date, timeIndex);

    QList<double> values = calculateSpeeds(trips, speedIndex);
    populate(values);
}


void MainWindow::populate(const QList<double> &values)
{
    QwtPlotItemList items = grid->itemList(QwtPlotItem::Rtti_PlotHistogram);
    for(int i = 0; i < items.size(); i++)
    {
        items.at(i)->detach();
    }

    Histogram *histogram = new Histogram( "Speed", Qt::red );
    histogram->setValues(values.size(), values );
    histogram->attach( grid );
}


QList<double> MainWindow::calculateSpeeds(const QList<Trip> &trips, int speed)
{
    QList<double> values;
    if(speed == 0)
    {
        for(int i = 0; i < trips.size(); i++)
        {
            values.append(trips.at(i).getMaxSpeed());
        }
    }
    else if(speed == 1)
    {
        for(int i = 0; i < trips.size(); i++)
        {
            values.append(trips.at(i).getAvgSpeed());
        }
    }
    return values;
}


void MainWindow::setupPlotArea()
{
    grid->setCanvasBackground( QColor( Qt::gray ) );
    grid->plotLayout()->setAlignCanvasToScales( true );

    //TODO here is axistitles.
//        grid->setAxisTitle( QwtPlot::yLeft, "Speed" );
//        grid->setAxisTitle( QwtPlot::xBottom, "Number of Hours" );

    grid->replot(); // creating the legend items
    grid->setAutoReplot( true );

    QwtPlotGrid *plotgrid = new QwtPlotGrid;
    plotgrid->enableX( false );
    plotgrid->enableY( true );
    plotgrid->enableXMin( false );
    plotgrid->enableYMin( true );
    plotgrid->attach( grid );
}

