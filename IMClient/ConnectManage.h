#pragma once
#include<QString>
#include<QWidget>
#include"User.h"
class MainWindow;
class QTcpSocket;
class QHostAddress;
class ConnectManage:public QWidget
{
	Q_OBJECT
private:
	QTcpSocket *tcpSocket;      //socket
	int port;		//端口号
	QHostAddress *serverIP;
	QString ip;
public:
	MainWindow *mainWindow;
	User* user;
public:
	ConnectManage();
	~ConnectManage();
	int ConnectServer();
	void Disconnect();
	void setUser(const User &tuser);
	//发送信息
	int sendMessage(const QString &message);

public slots:
	//接收消息
	void recvMessage();
signals:
	void logSuccess();
	void logFailed();
};

