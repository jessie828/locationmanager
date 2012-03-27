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
    //TODO make this configureable so you dont have to recompile when you need to test.
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
        .arg(trip->calculateDistance())
        .arg(trip->calculateAvgSpeed())
        .arg(trip->calculateMaxSpeed());
    query.exec(queryString);
        if (!query.isActive())
        {
            QMessageBox::warning(0, QObject::tr("Database Error while inserting a Trip"), query.lastError().text());
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
        QMessageBox::warning(0, QObject::tr("Database Error while inserting a Location"), query.lastError().text());
        return false;
    }
    return true;
}


bool Database::insert(Tank *tank)
{
    QSqlQuery query;
    QString queryString = QString("INSERT INTO Tank (date, liters, pricePerLiter, mileage, location ) "
        "VALUES ('%1', %2, %3, %4, '%5')")
        .arg(tank->getDate().toString(QString("yyyy-MM-dd")))
        .arg(tank->getLiters())
        .arg(tank->getPricePerLiter())
        .arg(tank->getMileage())
        .arg(tank->getLocation());
    query.exec(queryString);

    if (!query.isActive())
    {
        QMessageBox::warning(0, QObject::tr("Database Error while inserting a Tank"), query.lastError().text());
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


QList<Trip> Database::getAllTrips(const QDate &date)
{
    QString dateFormat = "yyyy-MM-dd";
    QDate borderDate = date.addDays(1);
    QSqlQuery query;
    QString queryString = QString("SELECT * FROM Trips WHERE startdate BETWEEN '%1' AND '%2'")
        .arg(date.toString(dateFormat))
        .arg(borderDate.toString(dateFormat));

    query.exec(queryString);
    if(!query.isActive())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"), query.lastError().text());
    }

    QList<Trip> trips;
    QString returnDateFormat = "yyyy-MM-dd'T'hh:mm:ss";
    while(query.next())
    {
        int tripId = query.value(0).toInt();
        Trip newTrip(tripId);
        newTrip.setStartDate(QDateTime::fromString(query.value(1).toString(), returnDateFormat));
        newTrip.setStopDate(QDateTime::fromString(query.value(2).toString(), returnDateFormat));
        newTrip.setDuration(query.value(3).toInt());
        newTrip.setDistance(query.value(4).toInt());
        newTrip.setAvgSpeed(query.value(5).toDouble());
        newTrip.setMaxSpeed(query.value(6).toDouble());

        trips.append(newTrip);
    }

    return trips;
}


QList<Tank> Database::getAllTanks(const QDate &date)
{
    QString dateFormat = "yyyy-MM-dd";
    QSqlQuery query;
    QString queryString = QString("SELECT * FROM Tank WHERE date = '%1'")
        .arg(date.toString(dateFormat));

    query.exec(queryString);
    if(!query.isActive())
    {
        QMessageBox::warning(0, QObject::tr("Database Error"), query.lastError().text());
    }

    QList<Tank> tanks;
    while(query.next())
    {
        Tank newTank;
        newTank.setId(query.value(0).toInt());
        newTank.setDate(QDate::fromString(query.value(1).toString(), dateFormat));
        newTank.setLiters(query.value(2).toDouble());
        newTank.setPricePerLiter(query.value(3).toDouble());
        newTank.setMileage(query.value(4).toInt());
        newTank.setLocation(query.value(5).toString());

        tanks.append(newTank);
    }

    return tanks;
}


Database::Database()
{
}


//TODO fix closing DB when app closes.
