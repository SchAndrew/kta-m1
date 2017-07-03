#include "admformular.h"

ADMFormular::ADMFormular(QObject *parent) : QObject(parent)
{
  Depot = new QString();
  Operator = new QString();
  Locomotive = new QString();
  LeftWheelN = new QString();
  LeftWheelD = new QString();
  RightWheelN = new QString();
  RightWheelD = new QString();
  Notes = new QString();
}

ADMFormular::~ADMFormular()
{
  this->Clear();
}

void ADMFormular::Clear()
{
  Depot->clear(); Operator->clear(); Locomotive->clear();
  LeftWheelN->clear();RightWheelN->clear();
  LeftWheelD->clear();RightWheelD->clear();
  Notes->clear();
}

bool ADMFormular::Filled()
{
  return (
    !Depot->isEmpty() && !Operator->isEmpty() && !Locomotive->isEmpty() &&
    !LeftWheelN->isEmpty() && !RightWheelN->isEmpty() &&
    !LeftWheelD->isEmpty() && !RightWheelD->isEmpty()
  );
}
