/********************************************************************************
** Form generated from reading UI file 'user_admin.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_ADMIN_H
#define UI_USER_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_admin
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *HTMLButton;
    QPushButton *CSVButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *user_admin)
    {
        if (user_admin->objectName().isEmpty())
            user_admin->setObjectName("user_admin");
        user_admin->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(user_admin);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(user_admin);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        HTMLButton = new QPushButton(user_admin);
        HTMLButton->setObjectName("HTMLButton");

        verticalLayout->addWidget(HTMLButton);

        CSVButton = new QPushButton(user_admin);
        CSVButton->setObjectName("CSVButton");

        verticalLayout->addWidget(CSVButton);

        pushButton = new QPushButton(user_admin);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(user_admin);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(user_admin);
        QObject::connect(pushButton, SIGNAL(clicked()), user_admin, SLOT(showAdmin()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), user_admin, SLOT(showUser()));
        QObject::connect(HTMLButton, SIGNAL(clicked()), user_admin, SLOT(initializeHTMLWatchList()));
        QObject::connect(CSVButton, SIGNAL(clicked()), user_admin, SLOT(initializeCSVWatchList()));

        QMetaObject::connectSlotsByName(user_admin);
    } // setupUi

    void retranslateUi(QWidget *user_admin)
    {
        user_admin->setWindowTitle(QCoreApplication::translate("user_admin", "user_admin", nullptr));
        label->setText(QCoreApplication::translate("user_admin", "Choose a mode", nullptr));
        HTMLButton->setText(QCoreApplication::translate("user_admin", "HTML file", nullptr));
        CSVButton->setText(QCoreApplication::translate("user_admin", "CSV file", nullptr));
        pushButton->setText(QCoreApplication::translate("user_admin", "Admin Mode", nullptr));
        pushButton_2->setText(QCoreApplication::translate("user_admin", "User Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_admin: public Ui_user_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_ADMIN_H
