/*
 * main.cpp
 *
 *  Created on: Jan 28, 2012
 *      Author: jessie
 */

#include <stdio.h>
#include "databaseConnection.h"
#include "saxHandler.h"

#include <QApplication>

#include "mainWindow.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    MainWindow *window = new MainWindow;
    window->show();

    if (!Database::getInstance()->createConnection())
    {
        return -1;
    }
    TcxSaxHandler handler;
    handler.parseFile(QString("/home/jessie/my_tracks/tcx/demo.tcx"));
    return a.exec();
}

