#include "devicewidget.h"
#include "ui_devicewidget.h"

DeviceWidget::DeviceWidget(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceWidget)
{
    ui->setupUi(this);
    ui->name->setText(name);
}

DeviceWidget::~DeviceWidget()
{
    delete ui;
}

void DeviceWidget::set_hostname(const QString &hostname)
{
    ui->hostname->setText(hostname);
}

void DeviceWidget::set_address(const QString &address)
{
    ui->address->setText(address);
}

void DeviceWidget::set_data(const QString &data)
{
    // ui->data->setText(data);
}

QString DeviceWidget::get_name() const
{
    return ui->name->text();
}