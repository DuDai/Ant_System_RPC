/********************************************************************************
** Form generated from reading UI file 'antsystem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANTSYSTEM_H
#define UI_ANTSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_antsystemClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *antsystemClass)
    {
        if (antsystemClass->objectName().isEmpty())
            antsystemClass->setObjectName(QString::fromUtf8("antsystemClass"));
        antsystemClass->resize(600, 400);
        menuBar = new QMenuBar(antsystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        antsystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(antsystemClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        antsystemClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(antsystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        antsystemClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(antsystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        antsystemClass->setStatusBar(statusBar);

        retranslateUi(antsystemClass);

        QMetaObject::connectSlotsByName(antsystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *antsystemClass)
    {
        antsystemClass->setWindowTitle(QCoreApplication::translate("antsystemClass", "antsystem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class antsystemClass: public Ui_antsystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANTSYSTEM_H
