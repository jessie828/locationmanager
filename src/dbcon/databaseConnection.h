#ifndef DATABASECONNECTION_H_
#define DATABASECONNECTION_H_

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

class DatabaseConnection
{

public:
	static bool createConnection();

};


#endif /* DATABASECONNECTION_H_ */
