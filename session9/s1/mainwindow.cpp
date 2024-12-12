#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <QFileDialog>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::addContact);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::deleteContact);
    connect(ui->btnEdit, &QPushButton::clicked, this, &MainWindow::editContact);
    connect(ui->btnAddFav, &QPushButton::clicked, this, &MainWindow::addFavorite);
    connect(ui->btnRemoveFav, &QPushButton::clicked, this, &MainWindow::removeFavorite);
    connect(ui->btnSave, &QPushButton::clicked, this, &MainWindow::saveContact);
    connect(ui->btnLoad, &QPushButton::clicked, this, &MainWindow::loadContact);
    connect(ui->btnImport, &QPushButton::clicked, this, &MainWindow::importContacts);
    connect(ui->btnExport, &QPushButton::clicked, this, &MainWindow::exportContacts);
    connect(ui->btnRefresh, &QPushButton::clicked, this, &MainWindow::refreshContacts);

    new QShortcut(QKeySequence("Ctrl+S"), this, SLOT(saveContact()));
    new QShortcut(QKeySequence("Ctrl+L"), this, SLOT(loadContact()));
    new QShortcut(QKeySequence("Ctrl+E"), this, SLOT(exportContacts()));
    new QShortcut(QKeySequence("Ctrl+I"), this, SLOT(importContacts()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addContact() {
    QString name = ui->lineEditName->text();
    QString type = ui->lineEditType->text();
    QString number = ui->lineEditNumber->text();

    if (name.isEmpty() || type.isEmpty() || number.isEmpty()) {
        QMessageBox::warning(this, "wrong", "please fill in all fields");
        return;
    }

    contacts.addContact(name.toStdString(), type.toStdString(), number.toStdString());
    ui->listWidgetContacts->addItem(name);
    ui->lineEditName->clear();
    ui->lineEditType->clear();
    ui->lineEditNumber->clear();
}

void MainWindow::deleteContact() {
    QListWidgetItem *selectedItem = ui->listWidgetContacts->currentItem();
    if (!selectedItem) {
        QMessageBox::critical(this, "wrong", "please select a contact");
        return;
    }

    QString name = selectedItem->text();
    contacts.deleteContact(name.toStdString());
    delete selectedItem;
}

void MainWindow::editContact() {
    QListWidgetItem *selectedItem = ui->listWidgetContacts->currentItem();
    if (!selectedItem) {
        QMessageBox::critical(this, "wrong", "please select a contact");
        return;
    }

    QString oldName = selectedItem->text();
    QString newName = ui->lineEditName->text();
    if (newName.isEmpty()) {
        QMessageBox::critical(this, "wrong", "please fill the name field");
        return;
    }

    contacts.editContact(oldName.toStdString(), newName.toStdString());
    selectedItem->setText(newName);
}

void MainWindow::addFavorite() {
    QListWidgetItem *selectedItem = ui->listWidgetContacts->currentItem();
    if (!selectedItem) {
        QMessageBox::critical(this, "wrong", "please select a contact");
        return;
    }

    QString name = selectedItem->text();
    contacts.addFav(name.toStdString());
    ui->listWidgetFavorites->addItem(name);
}

void MainWindow::removeFavorite() {
    QListWidgetItem *selectedItem = ui->listWidgetFavorites->currentItem();
    if (!selectedItem) {
        QMessageBox::critical(this, "wrong", "please select a favorite contact");
        return;
    }

    QString name = selectedItem->text();
    contacts.remFav(name.toStdString());
    delete selectedItem;
}

void MainWindow::saveContact() {
    ofstream file("contacts_save.txt");
    contacts.saveToFile(file);
    file.close();
    QMessageBox::information(this, "success", "contacts saved successfully");
}

void MainWindow::loadContact() {
    std::ifstream file("contacts_load.txt");


    string name, type, number;
    while (file >> name) {
        file >> type;
        file >> number;

        contacts.addContact(name, type, number);
    }
    file.close();
}





void MainWindow::importContacts() {

    QString fileName = QFileDialog::getOpenFileName(this, "import", "", "Text Files (*.txt);;All Files (*)");

    ifstream file(fileName.toStdString());
    string name, type, number;
    while (file >> name) {
        file >> type;
        file >> number;

        contacts.addContact(name, type, number);
    }
    file.close();
}



void MainWindow::exportContacts() {

    QString fileName = QFileDialog::getSaveFileName(this, "export", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    ofstream file(fileName.toStdString());


    contacts.saveToFile(file);
    file.close();
    QMessageBox::information(this, "success", "contacts exported successfully");
}



void MainWindow::refreshContacts(){
    ui->listWidgetContacts->clear();
    for (auto i : contacts.getContacts()) {
        ui->listWidgetContacts->addItem(QString::fromStdString(i.first));
    }
}



