#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainWindow.h"
#include "databaseConnection.h"
#include "histogram.h"

#include <QDate>
#include <QListWidgetItem>

class MainWindow: public QMainWindow, private Ui::locationManagerMainWindow
{
        Q_OBJECT

    public:
        MainWindow();
        void populate(const QList<double> &values);

    private:
        QString durationToString(int duration) const;

    public slots:
        void openTripImportDialog();
        void openMultiTripImportDialog();
        void openTankImportDialog();
        void fillOverviewList(QDate date);
        void fillTable(QDate date);
        void paintMontlyAvgSpeed(int tabId);

};

#endif
