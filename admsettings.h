#ifndef ADMSETTINGS_H
#define ADMSETTINGS_H

#include <QObject>
#include <QSettings>
#include <QTextCodec>
#include "admformular.h"

class ADMSettings : public QObject
{
  Q_OBJECT

public:
  explicit ADMSettings(QObject *parent = 0);
  virtual ~ADMSettings();

  QString GetVal(const QString k);
  void SetVal(const QString k, QString *v);

  void GetFormular(ADMFormular *f);
  void SetFormular(ADMFormular *f);

private:
  QSettings *s;
  QTextCodec *c = QTextCodec::codecForName("Windows-1251");
};

#endif // ADMSETTINGS_H
