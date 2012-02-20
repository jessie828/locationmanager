#ifndef SAXHANDLER_H_
#define SAXHANDLER_H_

#include "location.h"
#include "trip.h"
#include "databaseConnection.h"

#include <QXmlDefaultHandler>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QXmlSimpleReader>

class TcxSaxHandler: public QXmlDefaultHandler
{
public:
    TcxSaxHandler();
    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);
    bool parseFile(const QString &fileName);

public:
    static const QString DATEFORMAT;
    static const QString TCX;

private:
    Location *m_location;
    Trip *m_trip;
    bool m_id;
    bool m_totalTimeSeconds;
    bool m_distanceMeter;
    bool m_time;
    bool m_latitude;
    bool m_longitude;
    bool m_altitude;
};

#endif /* SAXHANDLER_H_ */
