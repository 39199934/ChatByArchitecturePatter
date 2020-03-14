#include "TestUserDatabase.h"

TestUserDatabase::TestUserDatabase(QObject *parent)
	: DatabaseProtocol("testUser",parent)
{
}

TestUserDatabase::~TestUserDatabase()
{
}


int TestUserDatabase::append(const TestUser& t)
{
	QString queryString = "INSERT INTO `" + databaseName + "`.`" + tableName + "` (`name`) VALUES ( " + t.name + " ); ";
	return query(queryString);
	return 0;
}

int TestUserDatabase::remove(QString key, QVariant value)
{
	return 0;
}

QVector<TestUser> TestUserDatabase::search(QString key, QVariant value)
{
	return QVector<TestUser>();
}

int TestUserDatabase::update(QString key, QVariant value, const TestUser& t)
{
	return 0;
}

QString TestUserDatabase::getCreateString()
{
	return "( `name` CHAR(20) ) CHARSET=utf8; ";
}
