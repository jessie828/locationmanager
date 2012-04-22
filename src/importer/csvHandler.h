#ifndef CSVHANDLER_H_
#define CSVHANDLER_H_

#include "location.h"
#include "trip.h"
#include "databaseConnection.h"

#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QIODevice>


class CsvHandler
{
    public:
        CsvHandler();
        bool parseFile(const QString &fileName);

    public:
        static const QString CSV;

};

#endif /* CSVHANDLER_H_ */
