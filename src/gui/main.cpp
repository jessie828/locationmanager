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
    if (!Database::getInstance()->createConnection())
    {
        return -1;
    }

    QApplication a(argc, argv);
    MainWindow *window = new MainWindow;
    window->show();

    return a.exec();
}

