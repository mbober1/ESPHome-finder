#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QWidget>

namespace Ui {
class DeviceWidget;
}

class DeviceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceWidget(const QString &name, QWidget *parent = nullptr);
    ~DeviceWidget();

    void set_hostname(const QString &hostname);
    void set_address(const QString &address);
    void set_data(const QString &data);
    QString get_name() const;

private:
    Ui::DeviceWidget *ui;
};

#endif // DEVICEWIDGET_H
