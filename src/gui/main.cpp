/*
 * main.cpp
 *
 *  Created on: Jan 28, 2012
 *      Author: jessie
 */

#include <stdio.h>
#include "databaseConnection.h"

#include <QApplication>

#include "mainWindow.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    MainWindow *window = new MainWindow;
    window->show();

    if (!DatabaseConnection::createConnection())
    {
        return -1;
    }
    return a.exec();
}

