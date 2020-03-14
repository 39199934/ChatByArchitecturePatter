#include "ChatByArchitecturePatter.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "TestUserDatabase.h"
#include "TestUser.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//ChatByArchitecturePatter w;
	//w.show();

	auto t = TestUser("rolodestar");
	TestUserDatabase td;

	td.createTable();
	td.append(t);
	return a.exec();
}
