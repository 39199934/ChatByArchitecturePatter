#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatByArchitecturePatter.h"

class ChatByArchitecturePatter : public QMainWindow
{
	Q_OBJECT

public:
	ChatByArchitecturePatter(QWidget *parent = Q_NULLPTR);

private:
	Ui::ChatByArchitecturePatterClass ui;
};
