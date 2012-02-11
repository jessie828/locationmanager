#include "databaseConnection.h"

bool DatabaseConnection::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("locationDB");
    db.setUserName("locationuser");
    db.setPassword("locationuser");
    if (!db.open())
    {
        QString errorMessage = db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database Error"), errorMessage);
        return false;
    }
    return true;
}

