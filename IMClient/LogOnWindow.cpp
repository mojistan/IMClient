#include"LogOnWindow.h"
#include "ConnectManage.h"
#include <QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QMessagebox>
LogOnWindow::LogOnWindow(QWidget *parent)
	: QDialog(parent)
{
	setGeometry(500, 200,500,400);
	setWindowTitle(tr("Log in"));
	connectManage = new ConnectManage();
	QPushButton *connectBtn = new QPushButton(tr("Connect Button"));
	connect(connectBtn, SIGNAL(clicked()), this, SLOT(slotConnect()));
	connect(connectManage, SIGNAL(logSuccess()), this, SLOT(slotLogSuccess()));
	connect(connectManage, SIGNAL(logFailed()), this, SLOT(slotLogFailed()));
	QLabel* idLabel = new QLabel("ID");
	idLabel->setMaximumHeight(15);
	QLabel* PasswordLabel = new QLabel("Password");
	PasswordLabel->setMaximumHeight(15);

	idEdit = new QLineEdit();
	idEdit->setMaximumHeight(50);


	PasswordEdit = new QLineEdit();
	PasswordEdit->setMaximumHeight(50);

	mainLayout = new QGridLayout(this);
	mainLayout->addWidget(idLabel);
	mainLayout->addWidget(idEdit);

	mainLayout->addWidget(PasswordLabel);
	mainLayout->addWidget(PasswordEdit);

	mainLayout->addWidget(connectBtn);
	this->setLayout(mainLayout);
}

void LogOnWindow::slotConnect()
{
	QString id = idEdit->text();
	QByteArray idByteArray = id.toLocal8Bit();
	QString pswrd = PasswordEdit->text();
	QByteArray pswrdByteArray = pswrd.toLocal8Bit();
	if (!id.isEmpty() && !pswrd.isEmpty())
	{
		user = new User(idByteArray.data(), pswrdByteArray.data());
		connectManage->setUser(*user);
		connectManage->ConnectServer();                 //尝试与服务器的连接
	}
	else return;

	//this->hide();
}
LogOnWindow::~LogOnWindow()
{
	if (connectManage != NULL) 
	{
		delete connectManage;
		connectManage = NULL;
	}
	if (mainLayout != NULL) 
	{
		delete mainLayout;
		mainLayout = NULL;
	}

	if (idEdit != NULL) 
	{
		delete idEdit;
		idEdit = NULL;
	}
	if (PasswordEdit != NULL)
	{
		delete PasswordEdit;
		PasswordEdit = NULL;
	}
	if (user != NULL)
	{
		delete user;
		user = NULL;
	}
}
void LogOnWindow::slotLogSuccess()
{
	MainWindow* mainWindow = new MainWindow();

	mainWindow->setConnectManage(*connectManage);
	connectManage->mainWindow = mainWindow;
	mainWindow->show();
	this->hide();
}
void LogOnWindow::slotLogFailed()
{
	QMessageBox::information(NULL, "Log in falied", "check your ID and password");
}