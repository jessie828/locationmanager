#include <QtGui>

#include "mainWindow.h"
#include "tripImportDialog.h"
#include "tankImportDialog.h"

MainWindow::MainWindow()
{
    setupUi(this);

    connect(actionImport_Trip, SIGNAL(activated()), this, SLOT(openTripImportDialog()));
    connect(actionImport_Tank, SIGNAL(activated()), this, SLOT(openTankImportDialog()));
    connect(calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(fillOverviewList(QDate)));
    connect(actionExit, SIGNAL(activated()), this, SLOT(close()));
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


void MainWindow::fillOverviewList(QDate date)
{
    QList<Trip*> trips;
    QList<Tank*> tanks;
    Database::getInstance()->getAllTrips(trips, date);
    Database::getInstance()->getAllTanks(tanks, date);

}
