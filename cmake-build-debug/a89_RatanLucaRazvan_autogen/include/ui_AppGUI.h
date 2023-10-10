/********************************************************************************
** Form generated from reading UI file 'appgui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPGUI_H
#define UI_APPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppGUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *movielistwidget;
    QFormLayout *formLayout;
    QLabel *title;
    QLineEdit *titleLineEdit;
    QLabel *genre;
    QLineEdit *genreLineEdit;
    QLabel *yearofrelease;
    QLineEdit *yearOfReleaseLineEdit;
    QLabel *numberoflikes;
    QLineEdit *numberOfLikesLineEdit;
    QLabel *trailer;
    QLineEdit *trailerLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *pushButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;

    void setupUi(QWidget *AppGUI)
    {
        if (AppGUI->objectName().isEmpty())
            AppGUI->setObjectName("AppGUI");
        AppGUI->resize(512, 379);
        verticalLayout_2 = new QVBoxLayout(AppGUI);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        movielistwidget = new QListWidget(AppGUI);
        movielistwidget->setObjectName("movielistwidget");

        verticalLayout->addWidget(movielistwidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        title = new QLabel(AppGUI);
        title->setObjectName("title");

        formLayout->setWidget(0, QFormLayout::LabelRole, title);

        titleLineEdit = new QLineEdit(AppGUI);
        titleLineEdit->setObjectName("titleLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, titleLineEdit);

        genre = new QLabel(AppGUI);
        genre->setObjectName("genre");

        formLayout->setWidget(1, QFormLayout::LabelRole, genre);

        genreLineEdit = new QLineEdit(AppGUI);
        genreLineEdit->setObjectName("genreLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, genreLineEdit);

        yearofrelease = new QLabel(AppGUI);
        yearofrelease->setObjectName("yearofrelease");

        formLayout->setWidget(2, QFormLayout::LabelRole, yearofrelease);

        yearOfReleaseLineEdit = new QLineEdit(AppGUI);
        yearOfReleaseLineEdit->setObjectName("yearOfReleaseLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, yearOfReleaseLineEdit);

        numberoflikes = new QLabel(AppGUI);
        numberoflikes->setObjectName("numberoflikes");

        formLayout->setWidget(3, QFormLayout::LabelRole, numberoflikes);

        numberOfLikesLineEdit = new QLineEdit(AppGUI);
        numberOfLikesLineEdit->setObjectName("numberOfLikesLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, numberOfLikesLineEdit);

        trailer = new QLabel(AppGUI);
        trailer->setObjectName("trailer");

        formLayout->setWidget(4, QFormLayout::LabelRole, trailer);

        trailerLineEdit = new QLineEdit(AppGUI);
        trailerLineEdit->setObjectName("trailerLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, trailerLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addButton = new QPushButton(AppGUI);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        pushButton = new QPushButton(AppGUI);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        deleteButton = new QPushButton(AppGUI);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        updateButton = new QPushButton(AppGUI);
        updateButton->setObjectName("updateButton");

        horizontalLayout->addWidget(updateButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AppGUI);
        QObject::connect(addButton, SIGNAL(clicked()), AppGUI, SLOT(addMovie()));
        QObject::connect(updateButton, SIGNAL(clicked()), AppGUI, SLOT(updateMovie()));
        QObject::connect(movielistwidget, SIGNAL(clicked(QModelIndex)), AppGUI, SLOT(elementClick()));
        QObject::connect(pushButton, SIGNAL(clicked()), AppGUI, SLOT(makeUndo()));

        QMetaObject::connectSlotsByName(AppGUI);
    } // setupUi

    void retranslateUi(QWidget *AppGUI)
    {
        AppGUI->setWindowTitle(QCoreApplication::translate("AppGUI", "AppGUI", nullptr));
        title->setText(QCoreApplication::translate("AppGUI", "Title", nullptr));
        genre->setText(QCoreApplication::translate("AppGUI", "Genre", nullptr));
        yearofrelease->setText(QCoreApplication::translate("AppGUI", "Year of Release", nullptr));
        numberoflikes->setText(QCoreApplication::translate("AppGUI", "Number of Likes", nullptr));
        trailer->setText(QCoreApplication::translate("AppGUI", "Trailer", nullptr));
        addButton->setText(QCoreApplication::translate("AppGUI", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("AppGUI", "Undo", nullptr));
        deleteButton->setText(QCoreApplication::translate("AppGUI", "Delete", nullptr));
        updateButton->setText(QCoreApplication::translate("AppGUI", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppGUI: public Ui_AppGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPGUI_H
