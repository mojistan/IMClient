/********************************************************************************
** Form generated from reading UI file 'IMClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMCLIENT_H
#define UI_IMCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IMClientClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IMClientClass)
    {
        if (IMClientClass->objectName().isEmpty())
            IMClientClass->setObjectName(QStringLiteral("IMClientClass"));
        IMClientClass->resize(600, 400);
        menuBar = new QMenuBar(IMClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        IMClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IMClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IMClientClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(IMClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        IMClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IMClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IMClientClass->setStatusBar(statusBar);

        retranslateUi(IMClientClass);

        QMetaObject::connectSlotsByName(IMClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *IMClientClass)
    {
        IMClientClass->setWindowTitle(QApplication::translate("IMClientClass", "IMClient", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IMClientClass: public Ui_IMClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMCLIENT_H
