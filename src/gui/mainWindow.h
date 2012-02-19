#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainWindow.h"
#include "databaseConnection.h"

class MainWindow: public QMainWindow, private Ui::locationManagerMainWindow
{
        Q_OBJECT

    public:
        MainWindow();

    public slots:
        void openImportDialog();

};

#endif
