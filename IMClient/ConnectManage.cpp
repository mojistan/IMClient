#include "ConnectManage.h"
#include<QWidget>
#include <QTcpSocket>
#include<QWebSocket>
#include <QHostAddress>
#include<QString>
#include<QList>
#include<Windows.h>
#include<MainWindow.h>
#include <QTextCodec>
#include<QDebug>
#include"User.h"
ConnectManage::ConnectManage()
{
	tcpSocket = new QTcpSocket(this);
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMessage()));
	port = 1234;
	ip = "192.168.0.11";
	//ip = "127.0.0.1";
	serverIP = new QHostAddress(ip);
}

ConnectManage::~ConnectManage()
{
}

int ConnectManage::ConnectServer()
{
	//连接服务器

	tcpSocket->connectToHost(*serverIP, port);
	QString msg;
	msg.append("LOGIN|");
	msg.append(user->getId());
	msg.append("|");
	msg.append(user->getPassword());
	msg.append("|");
	QByteArray msgByteArray = msg.toLocal8Bit();
	char* sendBuf = msgByteArray.data();
	int res = tcpSocket->write(sendBuf, strlen(sendBuf));
	int len = sizeof(sendBuf);
	return 0;
}

void ConnectManage::Disconnect()
{
	tcpSocket->disconnectFromHost();
}

void ConnectManage::setUser(const User& tuser)
{
	user = new User(tuser);
}

int ConnectManage::sendMessage(const QString & message)
{
	QString msg;
	msg.append("MSG|");					//消息类型	
	msg.append("GROUP1|");				//接受组
	msg.append(user->getNickname());       //用户名
	msg.append("|");
	msg.append(message);					//消息
	msg.append("|");
	QByteArray msgByteArray = msg.toLocal8Bit();
	char *sendBuf = msgByteArray.data();
	int res = tcpSocket->write(sendBuf,strlen(sendBuf));
	int len = sizeof(sendBuf);
	return 0;
}

void ConnectManage::recvMessage()
{

	QByteArray datagram;
	datagram.resize(tcpSocket->bytesAvailable());
	tcpSocket->read(datagram.data(), datagram.size());
	QTextCodec* codec = QTextCodec::codecForName("GBK");//指定QString的编码方式
	QString message = codec->toUnicode(datagram.data());//nameArray可以是char*，可以是QByteArray
	QList<QString> splitMsg = message.split("|");
	if(splitMsg[0] == "MSG")
		mainWindow->recvMessage(splitMsg[2],splitMsg[3]);
	else if (splitMsg[0] == "LOGIN")
	{
		if (splitMsg[1] == "SUCCESS") {
			QByteArray name = splitMsg[2].toLocal8Bit();
			qDebug() << strlen(name.data());
			user->setNickname(name.data(), strlen(name.data()));	
			emit logSuccess();
		}
		else if (splitMsg[1] == "FAILED")
		{
			Disconnect();
			emit logFailed();
		}
	}

}