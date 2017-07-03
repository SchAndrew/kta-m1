#include <QMessageBox>
#include "formularform.h"
#include "ui_formularform.h"

FormularForm::FormularForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::FormularForm)
{
  ui->setupUi(this);
}

FormularForm::~FormularForm()
{
  delete ui;
}

void FormularForm::on_boSave_clicked()
{
  if (!Check()) {
    QMessageBox *mb = new QMessageBox(this);
    mb->setIcon(QMessageBox::Critical);
    mb->setFont(this->font());
    mb->setText("Недопустимое/нечисловое значение в поле <Диаметр>");
    mb->setInformativeText("Сохранение невозможно!");
    mb->setStandardButtons(QMessageBox::Ok);
    mb->exec();
    return;
  }
  emit this->FormularFormClosed(1);
  this->close();
}

void FormularForm::on_bnCancel_clicked()
{
  emit this->FormularFormClosed(0);
  this->close();
}

bool FormularForm::Check()
{
  bool Ok = true;

  if (!ui->eLeftWheelD->text().isEmpty()) ui->eLeftWheelD->text().toDouble(&Ok);
  if (Ok && !ui->eRightWheelD->text().isEmpty()) ui->eRightWheelD->text().toDouble(&Ok);
  return (Ok);
}
