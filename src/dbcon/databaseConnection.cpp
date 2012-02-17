#include "databaseConnection.h"

Database *Database::m_instance = NULL;

Database* Database::getInstance()
{
    if(m_instance == NULL){
      m_instance = new Database();
    }
    return m_instance;
}


bool Database::createConnection()
{
    m_db = QSqlDatabase::database("location");
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("locationDB");
    m_db.setUserName("locationuser");
    m_db.setPassword("locationuser");
    if (!m_db.open())
    {
        QString errorMessage = m_db.lastError().text();
        QMessageBox::critical(0, QObject::tr("Database Error"), errorMessage);
        return false;
    }
    return true;
}


bool Database::insert(Trip *trip)
{
    printf("finally the trip that will go into the db: %s\n", trip->toString().toAscii().data());
    return true;
}


bool Database::insert(Location *location)
{
    printf("finally the location that will go into the db: %s\n", location->toString().toAscii().data());
    return true;
}

Database::Database()
{
}


//TODO fix closing DB when app closes.
