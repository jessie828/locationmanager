#ifndef IMPORTDIALOG_H
#define IMOPRTDIALOG_H

#include "ui_importDialog.h"

#include "saxHandler.h"

class ImportDialog : public QDialog, private Ui::importDialog
{
    Q_OBJECT

    public:
    ImportDialog(QWidget *parent = 0);

    public slots:
        void import();
        void browse();

};

#endif
