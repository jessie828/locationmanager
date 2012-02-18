#include <QtGui>

#include "importDialog.h"

ImportDialog::ImportDialog(QWidget *parent)
{
    setupUi(this);

    connect(importButton, SIGNAL(clicked()), this, SLOT(import()));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));
}


void ImportDialog::import()
{
    QString fileLocation = locationInputField->toPlainText();
    TcxSaxHandler handler;
    handler.parseFile(fileLocation);
    close();
}


void ImportDialog::browse()
{
    QString path;

    path = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        "/media/nas/Jessie/tracks",
        QString::null);

    locationInputField->setText( path );
}
