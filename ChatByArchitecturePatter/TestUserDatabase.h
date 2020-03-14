#pragma once

#include "DatabaseProtocol.h"
#include "TestUser.h"

class TestUserDatabase : public DatabaseProtocol<TestUser>
{
	Q_OBJECT

public:
	TestUserDatabase(QObject *parent = nullptr);
	~TestUserDatabase();

public:
	virtual int append(const TestUser& t);
	virtual int remove(QString key, QVariant value) override;
	virtual QVector<TestUser> search(QString key, QVariant value) ;
	virtual int update(QString key, QVariant value, const TestUser& t);
protected:
	//virtual int query(QString queryString);
	virtual QString getCreateString() override;
};
