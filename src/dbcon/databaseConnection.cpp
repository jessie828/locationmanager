#include "databaseConnection.h"

const QString Database::dateFormat = "yyyy-MM-dd hh:mm:ss";
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
    QSqlQuery query;
    QString queryString = QString("INSERT INTO Trips(startDate, endDate, duration, distance, average_speed, max_speed) VALUES('%1', '%2', %3, %4, %5, %6)")
        .arg(trip->getStartDate().toString(Database::dateFormat))
        .arg(trip->getStopDate().toString(Database::dateFormat))
        .arg(trip->getDuration())
        .arg(trip->getDistance())
        .arg(trip->getAvgSpeed())
        .arg(trip->getMaxSpeed());
    query.exec(queryString);
        if (!query.isActive())
        {
            QMessageBox::warning(0, QObject::tr("Database Error"), query.lastError().text());
            return false;
        }
        return true;
}


bool Database::insert(Location *location)
{
    QSqlQuery query;
    QString queryString = QString("INSERT INTO Locations (trip_id, time, altitude, latitude, longitude ) VALUES (%1, '%2', %3, %4, %5)")
        .arg(location->getTripId())
        .arg(location->getTime().toString(Database::dateFormat))
        .arg(location->getAltitude())
        .arg(location->getLatitude())
        .arg(location->getLongitude());
    query.exec(queryString);
    if (!query.isActive())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"), query.lastError().text());
        return false;
    }
    return true;
}


int Database::getLastTripId() const
{
    int result = -1;
    QSqlQuery query;
    QString queryString = "SELECT MAX(id) FROM Trips";
    query.exec(queryString);
    if(query.next())
    {
        result = query.value(0).toInt();
    }
    if (!query.isActive())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"), query.lastError().text());
    }
    return result;
}


Database::Database()
{
}


//TODO fix closing DB when app closes.
