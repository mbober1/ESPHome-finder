#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "avahi.hpp"
#include "devicewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    avahi* _avahi = discovery::get_avahi();
    connect(_avahi, &avahi::service_found,      this, &MainWindow::add_item);
    connect(_avahi, &avahi::service_lost,       this, &MainWindow::remove_item);
    connect(_avahi, &avahi::service_resolved,   this, &MainWindow::update_item);

    discovery::start_browsing("_esphomelib._tcp");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_item(const QString &name)
{
    static int column = 0;
    static int row = 0;

    DeviceWidget *device = new DeviceWidget(name, this);
    ui->devices_layout->addWidget(device, row, column++);

    if (column == 3)
    {
        column = 0;
        row++;
    }
}

void MainWindow::remove_item(const QString &name)
{
    for (size_t i = 0; i < ui->devices_layout->count(); i++)
    {
        auto widget = ui->devices_layout->itemAt(i)->widget();
        auto device = dynamic_cast<DeviceWidget*>(widget);
        
        if (device->get_name() == name)
        {
            ui->devices_layout->removeWidget(widget);
            delete widget;
            return;
        }
    }
}

void MainWindow::update_item(const QString &name, const QString &hostname, const QString &address, const QString &port, const QString &data)
{
    for (size_t i = 0; i < ui->devices_layout->count(); i++)
    {
        auto widget = ui->devices_layout->itemAt(i)->widget();
        auto device = dynamic_cast<DeviceWidget*>(widget);
        
        if (device->get_name() == name)
        {
            device->set_hostname(hostname);
            device->set_address(address);
            device->set_data(data);
            return;
        }
    }
}