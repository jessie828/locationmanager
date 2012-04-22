#include "csvHandler.h"

const QString CsvHandler::CSV = "csv";

CsvHandler::CsvHandler()
{

}


bool CsvHandler::parseFile(const QString &fileName)
{
    if(!Database::getInstance()->TripImported(fileName))
    {
        Database::getInstance()->insert(fileName, "csv");
        QFile file(fileName);
        if (!file.open (QIODevice::ReadOnly))
        {
            return false;
        }
        QTextStream stream(&file);
        QString line;
        QStringList values;
        while(!stream.atEnd())
        {
            line = stream.readLine();
            values = line.split(",");
            //"TYPE","TIME","LAT","LON","ALT","BEARING","ACCURACY","SPEED","NAME","DESCRIPTION","SEGMENT"
            //TODO do parsing here
            if(values.at(0) == "\"P\"")
            {

            }
        }
        file.close(); // when your done.
        return true;
    }
    else
    {
        QMessageBox::information(0, QObject::tr("Trip already imported."), QString("The trip you are trying to import is already imported."));
        return true;
    }
}

