#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainWindow.h"
#include "databaseConnection.h"

#include <stdlib.h>
#include <qpen.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_legend_item.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_column_symbol.h>
#include <qwt_series_data.h>

#include <QDate>
#include <QListWidgetItem>

class MainWindow: public QMainWindow, private Ui::locationManagerMainWindow
{
        Q_OBJECT

    public:
        MainWindow();

    private:
        QString durationToString(int duration) const;

    public slots:
        void openTripImportDialog();
        void openMultiTripImportDialog();
        void openTankImportDialog();
        void fillOverviewList(QDate date);
        void fillTable(QDate date);

};

#endif
