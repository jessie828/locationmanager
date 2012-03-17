#ifndef TANKIMPORTDIALOG_H_
#define TANKIMPORTDIALOG_H_

#include "tank.h"
#include "databaseConnection.h"

#include "ui_tankImportDialog.h"
#include <QtGui>

class TankImportDialog : public QDialog, private Ui::tankImportDialog
{
    Q_OBJECT

public:
    TankImportDialog(QWidget *parent = 0);

public slots:
    void accept();

private:
    Tank *m_tank;

};

#endif /* TANKIMPORTDIALOG_H_ */
