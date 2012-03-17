#ifndef TRIPIMPORTDIALOG_H
#define TRIPIMOPRTDIALOG_H

#include "ui_tripImportDialog.h"
#include <QtGui>

#include "saxHandler.h"

class TripImportDialog : public QDialog, private Ui::tripImportDialog
{
    Q_OBJECT

    public:
    TripImportDialog(QWidget *parent = 0);

    public slots:
        void import();
        void browse();

};

#endif
