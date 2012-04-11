#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainWindow.h"
#include "databaseConnection.h"
#include "histogram.h"

#include <QDate>
#include <QListWidgetItem>
#include <QTextCharFormat>

class MainWindow: public QMainWindow, private Ui::locationManagerMainWindow
{
        Q_OBJECT

    public:
        MainWindow();
        void populate(const QList<double> &values);

    private:
        QString durationToString(int duration) const;
        void setupPlotArea();
        QList<double> calculateSpeeds(const QList<Trip> &trips, int speed);
        void fillOverviewList(const QList<Trip> &trips, const QList<Tank> &tanks);
        void fillTripTable(const QList<Trip> &trips);
        void fillTankTable(const QList<Tank> &tanks);
        void markTripDays(const QList<Trip> &trips);
        void markTankDays(const QList<Tank> &tanks);
        void paintGraph(int timeIndex, int speedIndex, const QDate &date);
        void markDates();

    public slots:
        void openTripImportDialog();
        void openMultiTripImportDialog();
        void openTankImportDialog();
        void dateClicked(QDate date);
        void timeTypeChanged(int index);
        void speedTypeChanged(int index);

    private:
        QTextCharFormat m_format;
};

#endif
