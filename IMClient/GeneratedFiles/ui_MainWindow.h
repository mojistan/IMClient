/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *SendButton;
    QTextEdit *SendText;
    QTextEdit *ReceiveText;
    QLabel *label;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(919, 674);
        horizontalLayout_2 = new QHBoxLayout(MainWindow);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(MainWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(listWidget);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        SendButton = new QPushButton(MainWindow);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SendButton->sizePolicy().hasHeightForWidth());
        SendButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(SendButton);


        gridLayout->addLayout(horizontalLayout, 5, 2, 1, 1);

        SendText = new QTextEdit(MainWindow);
        SendText->setObjectName(QStringLiteral("SendText"));
        SendText->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SendText->sizePolicy().hasHeightForWidth());
        SendText->setSizePolicy(sizePolicy1);
        SendText->setMaximumSize(QSize(16777215, 200));
        SendText->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(SendText, 2, 1, 1, 2);

        ReceiveText = new QTextEdit(MainWindow);
        ReceiveText->setObjectName(QStringLiteral("ReceiveText"));
        sizePolicy1.setHeightForWidth(ReceiveText->sizePolicy().hasHeightForWidth());
        ReceiveText->setSizePolicy(sizePolicy1);
        ReceiveText->setReadOnly(true);

        gridLayout->addWidget(ReceiveText, 1, 1, 1, 2);

        label = new QLabel(MainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(label, 0, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        SendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        SendButton->setShortcut(QApplication::translate("MainWindow", "Shift+Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
