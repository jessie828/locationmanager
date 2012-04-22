#include "tripImportDialog.h"

TripImportDialog::TripImportDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);

    connect(importButton, SIGNAL(clicked()), this, SLOT(import()));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}


void TripImportDialog::import()
{
    QString fileLocation = locationInputField->text();
    if(fileLocation.isEmpty())
    {
        QMessageBox::warning(0, QObject::tr("Input Field Empty"), QString("The input field is empty.\nPlease select a valid file and try again."));
        return;
    }

    QFileInfo fileInfo(fileLocation);
    QString extension = fileInfo.suffix();
    bool parseSucessful;
    if(extension == TcxSaxHandler::TCX)
    {
        TcxSaxHandler handler;
        parseSucessful = handler.parseFile(fileLocation);
    }
    else if(extension == CsvHandler::CSV)
    {
        CsvHandler csvHanderl;
        parseSucessful = csvHanderl.parseFile(fileLocation);
    }
    else
    {
        QMessageBox::warning(0, QObject::tr("Wrong file extension"), QString("You have selected a wrong file extension"));
    }

    if(!parseSucessful)
    {
        QMessageBox::warning(0, QObject::tr("parse unsuccessful"), QString("The parsing of the trip is unsuccessful"));
    }
    else
    {
        close();
    }
}


void TripImportDialog::browse()
{
    QString path;

    path = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        "/home/jessie/my_tracks/tcx",
        QString::null);

    locationInputField->setText( path );
}
