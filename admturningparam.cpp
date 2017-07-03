#include "admturningparam.h"

/*
  int Profile = 0;
  int Direction = 0;
  struct wheel
  {
    double da = 0;
    double dd = 0;
    double df = 0;
    double w = 0;
  } lw, rw;
 */

ADMTurningParam::ADMTurningParam(QObject *parent) : QObject(parent)
{

}

void ADMTurningParam::Clear()
{
  Profile = 0; Direction = 0;
  lw.da = 0; lw.dd = 0; lw.df = 0; lw.w = 0;
  rw.da = 0; rw.dd = 0; rw.df = 0; rw.w = 0;
}
