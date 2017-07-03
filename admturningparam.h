#ifndef ADMTURNINGPARAM_H
#define ADMTURNINGPARAM_H

#include <QObject>

class ADMTurningParam : public QObject
{
  Q_OBJECT
public:
  explicit ADMTurningParam(QObject *parent = 0);

  int Profile = 0;
  int Direction = 0;
  struct wheel
  {
    double da = 0;
    double dd = 0;
    double df = 0;
    double w = 0;
  } lw, rw;
signals:

public slots:
  void Clear();
};

#endif // ADMTURNINGPARAM_H
