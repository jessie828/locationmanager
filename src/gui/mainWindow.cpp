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
    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(fillOverviewList(QDate)));
    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(fillTable(QDate)));
    connect(actionExit, SIGNAL(activated()), this, SLOT(close()));
    connect(actionImport_multiTrips, SIGNAL(activated()), this, SLOT(openMultiTripImportDialog()));

    connect(tabWidget, SIGNAL(currentChanged(int)), this, SLOT(paintMontlyAvgSpeed(int)));
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


void MainWindow::fillOverviewList(QDate date)
{
    tripViews->clear();
    QList<Trip> trips = Database::getInstance()->getAllTrips(date);
    QList<Tank> tanks = Database::getInstance()->getAllTanks(date);

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


void MainWindow::fillTable(QDate date)
{
    tableWidget->hide();
    tableWidget->clearContents();
    QList<Trip> trips = Database::getInstance()->getAllTrips(date);

    QStringList HorizontalLabels;
    HorizontalLabels << tr("startDate") << tr("EndDate") << tr("Duration") << tr("Distance") << tr("average Speed") << tr("Maximum speed");
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


void MainWindow::paintMontlyAvgSpeed(int tabId)
{
    if(tabId == 1)
    {
        int time = timeType->currentIndex();
        int speed = speedType->currentIndex();
        printf("clicked on date when in the graph view\n");
        QDate date = calendarWidget->selectedDate();

        grid->setCanvasBackground( QColor( Qt::gray ) );
        grid->plotLayout()->setAlignCanvasToScales( true );

        grid->setAxisTitle( QwtPlot::yLeft, "Number of People" );
        grid->setAxisTitle( QwtPlot::xBottom, "Number of Hours" );

        QwtLegend *legend = new QwtLegend;
        legend->setItemMode( QwtLegend::CheckableItem );
        grid->insertLegend( legend, QwtPlot::RightLegend );

        grid->replot(); // creating the legend items

        QwtPlotItemList items = grid->itemList( QwtPlotItem::Rtti_PlotHistogram );
        for ( int i = 0; i < items.size(); i++ )
        {
            if ( i == 0 )
            {
                QwtLegendItem *legendItem =
                    qobject_cast<QwtLegendItem *>( legend->find( items[i] ) );
                if ( legendItem )
                    legendItem->setChecked( true );

                items[i]->setVisible( true );
            }
            else
                items[i]->setVisible( false );
        }

        grid->setAutoReplot( true );

        QwtPlotGrid *plotgrid = new QwtPlotGrid;
        plotgrid->enableX( false );
        plotgrid->enableY( true );
        plotgrid->enableXMin( false );
        plotgrid->enableYMin( false );
        plotgrid->setMajPen( QPen( Qt::black, 0, Qt::DotLine ) );
        plotgrid->attach( grid );

        QList<double> values;
        values.append(400.0);
        values.append(300.0);
        populate(values);
    }
}


void MainWindow::populate(const QList<double> &values)
{
    Histogram *histogram = new Histogram( "Speed", Qt::red );
    histogram->setValues(values.size(), values );
    histogram->attach( grid );
}

