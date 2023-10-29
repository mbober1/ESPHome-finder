#pragma once
#include <QObject>

class avahi : public QObject
{
  Q_OBJECT

public:
  avahi();
  ~avahi();

signals:
  void service_found(const QString &name);
  void service_lost(const QString &name);
  void service_resolved(const QString &name, const QString &hostname, const QString &address, const QString &port, const QString &data);
};


namespace discovery
{
  void start_browsing(const char *type);
  avahi *get_avahi();
}