/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *movieWatchList;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout;
    QLabel *currentMovieLabel;
    QLineEdit *currentMovieLineEdit;
    QPushButton *nextButton;
    QLabel *genreLabel;
    QLineEdit *genreLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openButton;
    QPushButton *addMovieButton;
    QPushButton *deleteMovieButton;

    void setupUi(QWidget *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName("User");
        User->resize(567, 319);
        verticalLayout_2 = new QVBoxLayout(User);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        movieWatchList = new QListWidget(User);
        movieWatchList->setObjectName("movieWatchList");

        horizontalLayout->addWidget(movieWatchList);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(User);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(User);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(User);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(User);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(User);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(User);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_3);

        label_2 = new QLabel(User);
        label_2->setObjectName("label_2");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        lineEdit_4 = new QLineEdit(User);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_4);

        label_5 = new QLabel(User);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        lineEdit_5 = new QLineEdit(User);
        lineEdit_5->setObjectName("lineEdit_5");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_5);


        horizontalLayout->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        currentMovieLabel = new QLabel(User);
        currentMovieLabel->setObjectName("currentMovieLabel");

        gridLayout->addWidget(currentMovieLabel, 0, 0, 1, 2);

        currentMovieLineEdit = new QLineEdit(User);
        currentMovieLineEdit->setObjectName("currentMovieLineEdit");

        gridLayout->addWidget(currentMovieLineEdit, 0, 2, 1, 1);

        nextButton = new QPushButton(User);
        nextButton->setObjectName("nextButton");

        gridLayout->addWidget(nextButton, 0, 3, 1, 1);

        genreLabel = new QLabel(User);
        genreLabel->setObjectName("genreLabel");

        gridLayout->addWidget(genreLabel, 1, 0, 1, 1);

        genreLineEdit = new QLineEdit(User);
        genreLineEdit->setObjectName("genreLineEdit");

        gridLayout->addWidget(genreLineEdit, 1, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        openButton = new QPushButton(User);
        openButton->setObjectName("openButton");

        horizontalLayout_2->addWidget(openButton);

        addMovieButton = new QPushButton(User);
        addMovieButton->setObjectName("addMovieButton");

        horizontalLayout_2->addWidget(addMovieButton);

        deleteMovieButton = new QPushButton(User);
        deleteMovieButton->setObjectName("deleteMovieButton");

        horizontalLayout_2->addWidget(deleteMovieButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(User);
        QObject::connect(nextButton, SIGNAL(clicked()), User, SLOT(showDatabase()));
        QObject::connect(genreLineEdit, SIGNAL(textChanged(QString)), User, SLOT(resetCount()));
        QObject::connect(addMovieButton, SIGNAL(clicked()), User, SLOT(addToWatchList()));
        QObject::connect(deleteMovieButton, SIGNAL(clicked()), User, SLOT(deleteFromWatchList()));
        QObject::connect(openButton, SIGNAL(clicked()), User, SLOT(openWatchList()));
        QObject::connect(movieWatchList, SIGNAL(clicked(QModelIndex)), User, SLOT(showMovie()));

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QWidget *User)
    {
        User->setWindowTitle(QCoreApplication::translate("User", "User", nullptr));
        label->setText(QCoreApplication::translate("User", "Title", nullptr));
        label_3->setText(QCoreApplication::translate("User", "Number of Likes", nullptr));
        label_4->setText(QCoreApplication::translate("User", "Year of Release", nullptr));
        label_2->setText(QCoreApplication::translate("User", "Genre", nullptr));
        label_5->setText(QCoreApplication::translate("User", "Trailer", nullptr));
        currentMovieLabel->setText(QCoreApplication::translate("User", "Current Movie", nullptr));
        nextButton->setText(QCoreApplication::translate("User", "See Movies", nullptr));
        genreLabel->setText(QCoreApplication::translate("User", "Genre", nullptr));
        openButton->setText(QCoreApplication::translate("User", "Open Watchlist", nullptr));
        addMovieButton->setText(QCoreApplication::translate("User", "Add Movie", nullptr));
        deleteMovieButton->setText(QCoreApplication::translate("User", "Delete Movie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
