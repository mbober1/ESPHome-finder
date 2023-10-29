#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void add_item(const QString &name);
    void remove_item(const QString &name);
    void update_item(const QString &name, const QString &hostname, const QString &address, const QString &port, const QString &data);
};
#endif // MAINWINDOW_H
