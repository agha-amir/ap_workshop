/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelType;
    QLineEdit *lineEditType;
    QLabel *labelNumber;
    QLineEdit *lineEditNumber;
    QHBoxLayout *buttonLayout;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QListWidget *listWidgetContacts;
    QLabel *label_2;
    QListWidget *listWidgetFavorites;
    QGridLayout *gridLayoutSearch;
    QHBoxLayout *favButtonLayout;
    QPushButton *btnAddFav;
    QPushButton *btnRemoveFav;
    QHBoxLayout *saveLoadLayout;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QPushButton *btnImport;
    QPushButton *btnExport;
    QPushButton *btnRefresh;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1102, 740);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        labelName = new QLabel(centralwidget);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 0, 0, 1, 1);

        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName("lineEditName");

        gridLayout->addWidget(lineEditName, 0, 1, 1, 1);

        labelType = new QLabel(centralwidget);
        labelType->setObjectName("labelType");

        gridLayout->addWidget(labelType, 1, 0, 1, 1);

        lineEditType = new QLineEdit(centralwidget);
        lineEditType->setObjectName("lineEditType");

        gridLayout->addWidget(lineEditType, 1, 1, 1, 1);

        labelNumber = new QLabel(centralwidget);
        labelNumber->setObjectName("labelNumber");

        gridLayout->addWidget(labelNumber, 2, 0, 1, 1);

        lineEditNumber = new QLineEdit(centralwidget);
        lineEditNumber->setObjectName("lineEditNumber");

        gridLayout->addWidget(lineEditNumber, 2, 1, 1, 1);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");

        buttonLayout->addWidget(btnAdd);

        btnEdit = new QPushButton(centralwidget);
        btnEdit->setObjectName("btnEdit");

        buttonLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");

        buttonLayout->addWidget(btnDelete);


        gridLayout->addLayout(buttonLayout, 3, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        listWidgetContacts = new QListWidget(centralwidget);
        listWidgetContacts->setObjectName("listWidgetContacts");

        horizontalLayout->addWidget(listWidgetContacts);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        listWidgetFavorites = new QListWidget(centralwidget);
        listWidgetFavorites->setObjectName("listWidgetFavorites");

        horizontalLayout->addWidget(listWidgetFavorites);


        verticalLayout->addLayout(horizontalLayout);

        gridLayoutSearch = new QGridLayout();
        gridLayoutSearch->setObjectName("gridLayoutSearch");

        verticalLayout->addLayout(gridLayoutSearch);

        favButtonLayout = new QHBoxLayout();
        favButtonLayout->setObjectName("favButtonLayout");
        btnAddFav = new QPushButton(centralwidget);
        btnAddFav->setObjectName("btnAddFav");

        favButtonLayout->addWidget(btnAddFav);

        btnRemoveFav = new QPushButton(centralwidget);
        btnRemoveFav->setObjectName("btnRemoveFav");

        favButtonLayout->addWidget(btnRemoveFav);


        verticalLayout->addLayout(favButtonLayout);

        saveLoadLayout = new QHBoxLayout();
        saveLoadLayout->setObjectName("saveLoadLayout");
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");

        saveLoadLayout->addWidget(btnSave);

        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName("btnLoad");

        saveLoadLayout->addWidget(btnLoad);

        btnImport = new QPushButton(centralwidget);
        btnImport->setObjectName("btnImport");

        saveLoadLayout->addWidget(btnImport);

        btnExport = new QPushButton(centralwidget);
        btnExport->setObjectName("btnExport");

        saveLoadLayout->addWidget(btnExport);


        verticalLayout->addLayout(saveLoadLayout);

        btnRefresh = new QPushButton(centralwidget);
        btnRefresh->setObjectName("btnRefresh");

        verticalLayout->addWidget(btnRefresh);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Contacts Manager", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        labelType->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        labelNumber->setText(QCoreApplication::translate("MainWindow", "Number:", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "Add Contact", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "Edit Contact", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete Contact", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "contacts:", nullptr));
#if QT_CONFIG(tooltip)
        listWidgetContacts->setToolTip(QCoreApplication::translate("MainWindow", "List of Contacts", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("MainWindow", "favorites:", nullptr));
#if QT_CONFIG(tooltip)
        listWidgetFavorites->setToolTip(QCoreApplication::translate("MainWindow", "Favorites", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAddFav->setText(QCoreApplication::translate("MainWindow", "Add to Favorites", nullptr));
        btnRemoveFav->setText(QCoreApplication::translate("MainWindow", "Remove from Favorites", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Save Contacts", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "Load Contacts", nullptr));
        btnImport->setText(QCoreApplication::translate("MainWindow", "Import Contacts", nullptr));
        btnExport->setText(QCoreApplication::translate("MainWindow", "Export Contacts", nullptr));
        btnRefresh->setText(QCoreApplication::translate("MainWindow", "Refresh Contacts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
