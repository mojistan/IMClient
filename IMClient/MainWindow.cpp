#include "MainWindow.h"
#include<QKeyEvent>
MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.SendButton, SIGNAL(clicked()), this, SLOT(slotSendMessage()));

	connect(ui.SendText, SIGNAL(returnPressed()), this, SLOT(slotSendMessage()));

	ui.SendButton->setFocusPolicy(Qt::StrongFocus);
}

MainWindow::~MainWindow()
{
}

void MainWindow::slotSendMessage()
{
	QString message = ui.SendText->toPlainText();
	connectManage->sendMessage(message);
	//ui.ReceiveText->append(message);
	ui.SendText->clear();
}
void MainWindow::setConnectManage(ConnectManage &tConnect)
{
	connectManage = &tConnect;
}

void MainWindow::recvMessage(const QString &user,const QString & message)
{
	QString t_message = user+": "+message;

	ui.ReceiveText->append(t_message);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
	if ((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_Return))
	{
		slotSendMessage();
	}
}
