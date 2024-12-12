#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidgetItem>
#include "Contacts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addContact();
    void deleteContact();
    void editContact();
    void addFavorite();
    void removeFavorite();
    void saveContact();
    void loadContact();
    void importContacts();
    void exportContacts();
    void refreshContacts();

private:
    Ui::MainWindow *ui;
    Contacts contacts;
};

#endif
