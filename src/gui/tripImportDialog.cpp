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
    TcxSaxHandler handler;
    bool parseSucessful = handler.parseFile(fileLocation);
    if(!parseSucessful)
    {
        QMessageBox::warning(0, QObject::tr("Wrong file extension"), QString("You have selected a wrong file extension"));
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
