#pragma once

#include <QtWidgets/QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include "MainWindow.h"

#include"User.h"
#include"ConnectManage.h"
class LogOnWindow : public QDialog
{
	Q_OBJECT

public:
	LogOnWindow(QWidget *parent = Q_NULLPTR);
	~LogOnWindow();
private:
	QGridLayout *mainLayout;
	ConnectManage *connectManage;
	QLineEdit* idEdit;
	QLineEdit* PasswordEdit;
	User *user;
public slots:
	void slotConnect();
	void slotLogSuccess();
	void slotLogFailed();
};
