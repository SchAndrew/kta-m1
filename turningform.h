#ifndef TURNINGFORM_H
#define TURNINGFORM_H

#include <QWidget>
#include <QSettings>
#include <QTextCodec>
#include "admturningparam.h"

namespace Ui {
class TurningForm;
}

class TurningForm : public QWidget
{
  Q_OBJECT

public:
  explicit TurningForm(QWidget *parent = 0);
  ~TurningForm();
  Ui::TurningForm *ui;

signals:
  void TurningFormClosed(int mode);

private slots:
  void on_pbCancel_clicked();
  void on_pbSave_clicked();

  void on_cbxDirection_currentIndexChanged(int index);

private:
  QTextCodec *c = QTextCodec::codecForName("Windows-1251");
};

#endif // TURNINGFORM_H
