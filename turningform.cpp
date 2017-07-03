#include "turningform.h"
#include "ui_turningform.h"

TurningForm::TurningForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TurningForm)
{
  ui->setupUi(this);

  QSettings *p = new QSettings("profiles.ini", QSettings::IniFormat, this);
  p->setIniCodec(c);

  QStringList l = p->childGroups();
  QString *n = new QString;;
  for (int i = 0; i < l.size(); i++)
  {
    n->clear();n->append(l.at(i));n->append("/name");
    QString v = p->value(*n, "Error!").toString();
    ui->cbxProfile->addItem(v.toUtf8());
  }
  delete p;

  ui->cbxDirection->addItem(QIcon(":/32dir1.png"), "Наружу и внуть");
  ui->cbxDirection->addItem(QIcon(":/32dir2.png"), "От гребня наружу и внуть");
  ui->cbxDirection->addItem(QIcon(":/32dir3.png"), "Снаружи и изнутри к гребню");
  ui->cbxDirection->addItem(QIcon(":/32dir4.png"), "Внутрь");
  ui->cbxDirection->addItem(QIcon(":/32dir5.png"), "Наружу");

}

TurningForm::~TurningForm()
{
  delete ui;
}

void TurningForm::on_pbCancel_clicked()
{
  emit this->TurningFormClosed(0);
  this->close();
}

void TurningForm::on_pbSave_clicked()
{
  emit this->TurningFormClosed(1);
  this->close();
}

void TurningForm::on_cbxDirection_currentIndexChanged(int index)
{
  switch (index) {
    case 0:
      ui->gvDirPicture->setStyleSheet("background-color: gainsboro;"); break;
    case 1:
      ui->gvDirPicture->setStyleSheet("background-image: url(:/50dir1.png);");break;
    case 2:
      ui->gvDirPicture->setStyleSheet("background-image: url(:/50dir2.png);");break;
    case 3:
      ui->gvDirPicture->setStyleSheet("background-image: url(:/50dir3.png);");break;
    case 4:
      ui->gvDirPicture->setStyleSheet("background-image: url(:/50dir4.png);");break;
    case 5:
      ui->gvDirPicture->setStyleSheet("background-image: url(:/50dir5.png);");break;
    default:
      break;
    }
}
