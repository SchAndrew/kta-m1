#ifndef FORMULARFORM_H
#define FORMULARFORM_H
#include <QWidget>

namespace Ui {
  class FormularForm;
}

class FormularForm : public QWidget
{
  Q_OBJECT

signals:
  void FormularFormClosed(int mode);

public:
  explicit FormularForm(QWidget *parent = 0);
  ~FormularForm();
  Ui::FormularForm *ui;

private slots:
  void on_boSave_clicked();
  void on_bnCancel_clicked();

private:
  bool Check();
};

#endif // FORMULARFORM_H
