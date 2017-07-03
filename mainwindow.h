#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QSettings>
#include "admsettings.h"
#include "admformular.h"
#include "formularform.h"
#include "admturningparam.h"
#include "turningform.h"

const int bC11 = 11;
const int bC12 = 12;
const int bC21 = 21;
const int bC22 = 22;
const int bC31 = 31;
const int bC32 = 32;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void FormularFormClosed(int mode);
  void TurningFormClosed(int mode);

  void on_bnC11_clicked();
  void on_bnC12_clicked();

  void on_bnC31_clicked();

  void on_bn101_clicked();
  void on_bn102_clicked();
  void on_bn103_clicked();
  void on_bn104_clicked();
  void on_bn105_clicked();
  void on_bn106_clicked();
  void on_bn107_clicked();
  void on_bn108_clicked();
  void on_bn109_clicked();
  void on_bn110_clicked();
  void on_bn111_clicked();
  void on_bn112_clicked();
  void on_bn113_clicked();

  void on_bn201_clicked();
  void on_bn202_clicked();
  void on_bn203_clicked();
  void on_bn204_clicked();
  void on_bn205_clicked();
  void on_bn206_clicked();
  void on_bn207_clicked();
  void on_bn208_clicked();
  void on_bn209_clicked();
  void on_bn210_clicked();
  void on_bn211_clicked();
  void on_bn212_clicked();
  void on_bn213_clicked();

  void on_bn301_clicked();
  void on_bn302_clicked();
  void on_bn303_clicked();
  void on_bn304_clicked();
  void on_bn305_clicked();
  void on_bn306_clicked();
  void on_bn307_clicked();
  void on_bn308_clicked();
  void on_bn309_clicked();
  void on_bn310_clicked();
  void on_bn311_clicked();
  void on_bn312_clicked();
  void on_bn313_clicked();

  void on_bn401_clicked();
  void on_bn402_clicked();
  void on_bn403_clicked();
  void on_bn404_clicked();
  void on_bn405_clicked();
  void on_bn406_clicked();
  void on_bn407_clicked();
  void on_bn408_clicked();
  void on_bn409_clicked();
  void on_bn410_clicked();
  void on_bn411_clicked();
  void on_bn412_clicked();
  void on_bn413_clicked();

private:
  Ui::MainWindow *ui;

  QSignalMapper *smKbd;               //! To-Do
  QWidget *InFocus = 0;               //! InputWidget на форме в waFrame, получивший фокус

  ADMSettings *objSettings;           //! Объект параметров

  ADMFormular *Formular;              //! Объект формуляра
  FormularForm *objFormularForm = 0;  //! Объект формы формуляра FormularForm
  bool FormularFormOpened = false;    //! Флаг открыта/не открыта форма формуляра

  ADMTurningParam *TurningParam;      //! Объект параметров обточки
  TurningForm *objTurningForm = 0;    //! Объект формы параметров обточки TurningForm
  bool TurningFormOpened = false;     //! Флаг открыта/не открыта форма параметров обточки

  void DetectFocus(QWidget *w);
  void AddLetter(QString ch);
  void LockCmdKeys(int exclude);
  void UnlockCmdKeys();
  void LockKeyboard();
  void LockKeyboardA();
  void UnlockKeyboard();
};

#endif // MAINWINDOW_H
