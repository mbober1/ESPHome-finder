#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "avahi.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    avahi* _avahi = discovery::get_avahi();
    connect(_avahi, &avahi::service_found, this, &MainWindow::add_item);
    connect(_avahi, &avahi::service_lost, this, &MainWindow::remove_item);
    connect(_avahi, &avahi::service_resolved, this, &MainWindow::update_item);

    discovery::start_browsing("_esphomelib._tcp");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_item(const QString &name)
{
    new QListWidgetItem(name, ui->listWidget);
}

void MainWindow::remove_item(const QString &name)
{
    QList<QListWidgetItem *> items = ui->listWidget->findItems(name, Qt::MatchExactly);
    for (auto item : items)
    {
        delete item;
    }
}

void MainWindow::update_item(const QString &name, const QString &hostname, const QString &address, const QString &port, const QString &data)
{
    QList<QListWidgetItem *> items = ui->listWidget->findItems(name, Qt::MatchExactly);
    for (auto item : items)
    {
        item->setText(name + " " + hostname + " " + address + " " + port + " " + data);
    }
}