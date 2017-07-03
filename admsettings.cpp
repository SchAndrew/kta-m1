#include <QApplication>
#include "admsettings.h"

ADMSettings::ADMSettings(QObject *parent) : QObject(parent)
{
  s = new QSettings("KTA-M1.ini", QSettings::IniFormat, this);
  s->setIniCodec(c);

//  QVariant v = s->value("common/application", 0);
//  if (v == 0) {
//    s->setValue("common/application", qApp->applicationName());
//    s->setValue("common/version", qApp->applicationVersion());
//   s->sync();
//  }
}

ADMSettings::~ADMSettings()
{
  s->sync();
  delete s;
}

QString ADMSettings::GetVal(const QString k)
{
  QVariant t;
  t = s->value(k, 0);
  if (t == 0) {
    return("");
  }
  else {
    return(t.toString());
  }
}

void ADMSettings::SetVal(QString k, QString *v)
{
  QVariant t;
  s->setValue(k, *v);
}

void ADMSettings::GetFormular(ADMFormular *f)
{
  f->Depot->clear();f->Depot->append(GetVal("formular/depot"));
  f->Operator->clear();f->Operator->append(GetVal("formular/operator"));
  f->Locomotive->clear();f->Locomotive->append(GetVal("formular/locomotive"));
  f->LeftWheelN->clear();f->LeftWheelN->append(GetVal("formular/left_wheel_num"));
  f->LeftWheelD->clear();f->LeftWheelD->append(GetVal("formular/left_wheel_dia"));
  f->RightWheelN->clear();f->RightWheelN->append(GetVal("formular/right_wheel_num"));
  f->RightWheelD->clear();f->RightWheelD->append(GetVal("formular/right_wheel_dia"));
  f->Notes->clear();f->Notes->append(GetVal("formular/notes"));
}

void ADMSettings::SetFormular(ADMFormular *f)
{
  SetVal("formular/depot", f->Depot);
  SetVal("formular/operator", f->Operator);
  SetVal("formular/locomotive", f->Locomotive);
  SetVal("formular/left_wheel_num", f->LeftWheelN);
  SetVal("formular/left_wheel_dia", f->LeftWheelD);
  SetVal("formular/right_wheel_num", f->RightWheelN);
  SetVal("formular/right_wheel_dia", f->RightWheelD);
  SetVal("formular/notes", f->Notes);
}

