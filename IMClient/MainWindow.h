#pragma once

#include <QWidget>
#include "ui_MainWindow.h"
#include"ConnectManage.h"
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
	void setConnectManage(ConnectManage &tConnect);
	void recvMessage(const QString& user, const QString &message);
public slots:
	void slotSendMessage();
public:
	ConnectManage *connectManage;
private:
	Ui::MainWindow ui;
	virtual void keyPressEvent(QKeyEvent* event);
};
