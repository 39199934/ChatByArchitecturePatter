#include "DatabaseProtocol.h"
template<class T>
DatabaseProtocol<T>::DatabaseProtocol(QObject *parent)
	: QObject(parent),
	sqlName("QMYSQL"),
	hostName("192.168.31.101"),
	port(3306),
	userName("root"),
	password("lode801103"),
	databaseName("chatSql")
{
	db = QSqlDatabase::addDatabase(sqlName);
	db.setDatabaseName(databaseName);
	db.setHostName(hostName);
	db.setPassword(password);
	db.setPort(port);
	db.setUserName(userName);
	db.open();
	
}
template<class T>
DatabaseProtocol<T>::DatabaseProtocol(QString tableName, QObject* parent):
	tableName(tableName),
	DatabaseProtocol(parent)
{
}
template<class T>
DatabaseProtocol<T>::~DatabaseProtocol()
{
	if (db.isOpen()) {
		db.close();
	}
}
template<class T>
int DatabaseProtocol<T>::createTable()
{
	QString oriStr = "CREATE TABLE `" + databaseName + "`.`" + tableName + "` ";
	oriStr = oriStr + getCreateString();
	return query(oriStr);
}

template<class T>
int DatabaseProtocol<T>::dropTable()
{
	QString queryString = "DROP TABLE `" + databaseName + "`.`" + tableName + "`; ";
	
	return query(queryString);
}

template<class T>
int DatabaseProtocol<T>::query(QString queryString)
{
	QSqlQuery sqlQuery(db);
	if (sqlQuery.exec(queryString)) {
		return sqlQuery.numRowsAffected();
	}
	else {
		//emit signalDBHasError(sqlQuery.lastError());
		return -1;
	}
	
	
}
