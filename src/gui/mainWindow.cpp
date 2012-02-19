#include <QtGui>

#include "mainWindow.h"
#include "importDialog.h"

MainWindow::MainWindow()
{
    setupUi(this);

    connect(actionFrom_File, SIGNAL(activated()), this, SLOT(openImportDialog()));
}


void MainWindow::openImportDialog()
{
    ImportDialog *importDialog = new ImportDialog(this);
    importDialog->show();
}
