#ifndef MULTITRIPIMPORTDIALOG_H
#define MULTITRIPIMPORTDIALOG_H

#include "ui_multiTripImportDialog.h"
#include <QtGui>

#include "saxHandler.h"

class MultiTripImportDialog : public QDialog, private Ui::multiTripImportDialog
{
    Q_OBJECT

    public:
    MultiTripImportDialog(QWidget *parent = 0);

    private:
    QStringList m_fileNames;

    public slots:
        void import();
        void browse();

};

#endif
