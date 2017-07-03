#ifndef ADMFORMMULAR_H
#define ADMFORMMULAR_H

#include <QObject>

class ADMFormular : public QObject
{
  Q_OBJECT

public:
  explicit ADMFormular(QObject *parent = 0);
  ~ADMFormular();

  QString *Depot;
  QString *Operator;
  QString *Locomotive;
  QString *LeftWheelN;
  QString *LeftWheelD;
  QString *RightWheelN;
  QString *RightWheelD;
  QString *Notes;

  void Clear();
  bool Filled();
};

#endif // ADMFORMMULAR_H
