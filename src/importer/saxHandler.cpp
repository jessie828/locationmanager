#include "saxHandler.h"

QString TcxSaxHandler::dateFormat = "yyyy-MM-dd'T'hh:mm:ss'Z'";

TcxSaxHandler::TcxSaxHandler()
{
    m_id = false;
    m_totalTimeSeconds = false;
    m_distanceMeter = false;
    m_time = false;
    m_latitude = false;
    m_longitude = false;
    m_altitude = false;
}


bool TcxSaxHandler::startElement(const QString & /* namespaceURI */, const QString & /* localName */, const QString &qName, const QXmlAttributes &attributes)
{
    if (qName == "Activities")
    {
        int tripId = Database::getInstance()->getLastTripId();
        tripId++;
        m_trip = new Trip(tripId);
    }
    else if (qName == "Lap")
    {
        QDateTime startDate;
        QString startTime = attributes.value("StartTime");
        startDate = QDateTime::fromString(startTime, TcxSaxHandler::dateFormat);
        m_trip->setStartDate(startDate);
    }
    else if (qName ==  "TotalTimeSeconds")
    {
        m_totalTimeSeconds = true;
    }
    else if(qName == "DistanceMeters")
    {
        m_distanceMeter = true;
    }
    else if(qName == "Trackpoint")
    {
        m_location = new Location;
        m_location->setTripId(m_trip->getId());
    }
    else if(qName == "Time")
    {
        m_time = true;
    }
    else if(qName == "LatitudeDegrees")
    {
        m_latitude = true;
    }
    else if(qName == "LongitudeDegrees")
    {
        m_longitude = true;
    }
    else if(qName == "AltitudeMeters")
    {
        m_altitude = true;
    }
    return true;
}


bool TcxSaxHandler::characters(const QString &str)
{
    if(m_totalTimeSeconds)
    {
        int timeSeconds = str.toInt();
        QDateTime stopDate;
        stopDate = m_trip->getStartDate().addSecs(timeSeconds);
        m_trip->setStopDate(stopDate);
        m_trip->setDuration(timeSeconds);
        m_totalTimeSeconds = false;
    }
    else if (m_distanceMeter)
    {
        int distance = str.toInt();
        m_trip->setDistance(distance);
        m_distanceMeter = false;
    }
    else if (m_time)
    {
        QDateTime time = QDateTime::fromString(str, TcxSaxHandler::dateFormat);
        m_location->setTime(time);
        m_time = false;
    }
    else if(m_latitude)
    {
        double latitude = str.toDouble();
        m_location->setLatitude(latitude);
        m_latitude = false;
    }
    else if(m_longitude)
    {
        double longitude = str.toDouble();
        m_location->setLongitude(longitude);
        m_longitude = false;
    }
    else if(m_altitude)
    {
        double altidude = str.toDouble();
        m_location->setAltitude(altidude);
        m_altitude = false;
    }
    return true;
}


bool TcxSaxHandler::endElement(const QString & /* namespaceURI */,  const QString & /* localName */, const QString &qName)
{
    if (qName == "Trackpoint")
    {
        Database::getInstance()->insert(m_location);
        m_trip->appendLocation(m_location);
    }
    else if(qName == "Activities")
    {
        m_trip->calculateDistanceBetweenLocations();
        m_trip->calculateSpeed();
        Database::getInstance()->insert(m_trip);
    }
    return true;
}


bool TcxSaxHandler::fatalError(const QXmlParseException &exception)
{
    QMessageBox::warning(
        0,
        QObject::tr("SAX Handler"),
        QObject::tr("Parse error at line %1, column "
            "%2:\n%3.").arg(exception.lineNumber()).arg(
            exception.columnNumber()).arg(exception.message()));
    return false;
}


bool TcxSaxHandler::parseFile(const QString &fileName)
{
    QFile file(fileName);
    QXmlInputSource inputSource(&file);
    QXmlSimpleReader reader;
    TcxSaxHandler handler;
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);
    return reader.parse(inputSource);
}

