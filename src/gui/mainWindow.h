#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainWindow.h"

class MainWindow : public QMainWindow, private Ui::locationManagerMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
};

#endif
