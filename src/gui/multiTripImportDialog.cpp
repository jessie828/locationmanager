#include "multiTripImportDialog.h"

MultiTripImportDialog::MultiTripImportDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);

    connect(importButton, SIGNAL(clicked()), this, SLOT(import()));
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browse()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}


void MultiTripImportDialog::import()
{
    QStringList failedFiles;
    QString fileString;
    TcxSaxHandler handler;
    for(int i = 0; i < m_fileNames.size(); i++)
    {
        QString fileLocation = m_fileNames.at(i);
        if(fileLocation.isEmpty())
        {
            QMessageBox::warning(0, QObject::tr("Input Field Empty"), QString("The input field is empty.\nPlease select a valid file and try again."));
            return;
        }

        bool parseSucessful = handler.parseFile(fileLocation);
        if(!parseSucessful)
        {
            failedFiles.append(fileLocation);
        }
    }

    for(int i = 0; i < failedFiles.size(); i++)
    {
        fileString += QString("%1;").arg(failedFiles.at(i));
    }

    if(failedFiles.size() > 0)
    {
        QMessageBox::warning(0, QObject::tr("Wrong file extension"), QString("The following files could not be parsed due to a wrong file extension\n%1\n").arg(fileString));
    }
    else
    {
        close();
    }
}


void MultiTripImportDialog::browse()
{
    QString fileString;
    m_fileNames = QFileDialog::getOpenFileNames(
        this,
        "Choose a file to open",
        "/home/jessie/my_tracks/tcx",
        QString::null);

    for(int i = 0; i < m_fileNames.size(); i++)
    {
        fileString += QString("%1;").arg(m_fileNames.at(i));
    }

    locationInputField->setText(fileString);
}
