#include <QLineEdit>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formularform.h"
#include "ui_formularform.h"

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 * Конструктор формы MainWindow
 */
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

/*!
 * Инициализация объекта настроек приложения
 */
  objSettings = new ADMSettings();
/*!
 * Инициализация структуры данных формуляра
 */
  Formular = new ADMFormular(this);
  objSettings->GetFormular(Formular);
  Formular->LeftWheelN->clear();Formular->LeftWheelD->clear();
  Formular->RightWheelN->clear(); Formular->RightWheelD->clear();

  TurningParam = new ADMTurningParam(this);
  TurningParam->Clear();

  LockKeyboard();
}

MainWindow::~MainWindow()
{
  delete Formular;
  delete objSettings;
  delete ui;
}

void MainWindow::FormularFormClosed(int mode)
{
  if (mode == 1)
  {
    Formular->Depot->clear();
    Formular->Depot->append(objFormularForm->ui->eDepot->text());
    Formular->Locomotive->clear();
    Formular->Locomotive->append(objFormularForm->ui->eLocomotive->text());
    Formular->Operator->clear();
    Formular->Operator->append(objFormularForm->ui->eOperator->text());
    Formular->LeftWheelN->clear();
    Formular->LeftWheelN->append(objFormularForm->ui->eLeftWheelN->text());
    Formular->LeftWheelD->clear();
    Formular->LeftWheelD->append(objFormularForm->ui->eLeftWheelD->text());
    Formular->RightWheelN->clear();
    Formular->RightWheelN->append(objFormularForm->ui->eRightWheelN->text());
    Formular->RightWheelD->clear();
    Formular->RightWheelD->append(objFormularForm->ui->eRightWheelD->text());
    Formular->Notes->clear();
    Formular->Notes->append(objFormularForm->ui->eNotes->placeholderText());
    objSettings->SetFormular(Formular);
  }
  disconnect(objFormularForm, SIGNAL(FormularFormClosed(int)), this, SLOT(FormularFormClosed(int)));
  FormularFormOpened = false;
  UnlockCmdKeys();
}

void MainWindow::TurningFormClosed(int mode)
{
  if (mode == 1)
  {
  }
  disconnect(objTurningForm, SIGNAL(TurningFormClosed(int)), this, SLOT(TurningFormClosed(int)));
  TurningFormOpened = false;
  UnlockCmdKeys();
}

void MainWindow::DetectFocus (QWidget *w)
{
  if (w == 0) return;

  QObjectList children = w->children();
  if (children.count() == 0) return;
  foreach(QObject *child, children)
  {
    QWidget *childWidget = qobject_cast<QWidget*> (child);
    if ((childWidget != 0) && (childWidget->hasFocus()))
    {
      InFocus = childWidget;
      return;
    }
    DetectFocus(childWidget);
    if (InFocus != 0) return;
  }
}

void MainWindow::AddLetter(QString ch)
{
  QString *t, *c;
  QWidget *f = ui->waForm;

  InFocus = 0;
  DetectFocus(f);
  if (InFocus == 0) return;

  c = new QString(InFocus->metaObject()->className());
  if (c->compare("QLineEdit") == 0)
  {
    QLineEdit *le = qobject_cast<QLineEdit*> (InFocus);
    t = new QString(le->text());
    if (ch == "<<")
    {
      le->backspace();
      //QString *t1 = new QString(t->left(t->length() - 1));
      //le->setText(*t1);
      //delete t1;
    }
    else if (ch.isNull() || ch.isEmpty())
    {
      t->append(" "); le->setText(*t);
    }
    else
    {
      t->append(ch); le->setText(*t);
    }
    delete t;
  }
  else if (c->compare("QPlainTextEdit") == 0)
  {
    QPlainTextEdit *te = qobject_cast<QPlainTextEdit*> (InFocus);
    t = new QString(te->toPlainText());
    if (ch == "<<")
    {
      QString *t1 = new QString(t->left(t->length() - 1));
      te->setPlainText(*t1);
      te->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
      delete t1;
    }
    else if (ch == "CR")
    {
      te->appendPlainText("");
    }
    else if (ch.isNull() || ch.isEmpty())
    {
      //t->append(" "); te->setPlainText(*t);
      //te->appendPlainText(" ");
      te->insertPlainText(" ");
    }
    else
    {
      te->insertPlainText(ch);
      //te->appendPlainText(ch);
      //t->append(ch); te->setPlainText(*t);
    }
    delete t;
  }
  delete c;
}

void MainWindow::LockKeyboard()
{
  foreach(QObject *o, ui->glKbd->children())
  {
    qobject_cast<QWidget*>(o)->setEnabled(false);
  }
}

void MainWindow::LockKeyboardA()
{
  foreach(QObject *c, ui->glKbd->children())
  {
    QPushButton *b = qobject_cast<QPushButton*>(c);
    if (b->text().contains(QRegExp("[^0123456789-=.,/\\")))
    {
      b->setEnabled(false);
    }
  }
}

void MainWindow::UnlockKeyboard()
{
  foreach(QObject *b, ui->glKbd->children())
  {
    qobject_cast<QWidget*>(b)->setEnabled(true);
  }
}

void MainWindow::LockCmdKeys(int exclude)
{
  ui->bnC11->setEnabled(false);
  ui->bnC12->setEnabled(false);
  ui->bnC21->setEnabled(false);
  ui->bnC22->setEnabled(false);
  ui->bnC31->setEnabled(false);
  ui->bnC32->setEnabled(false);

  if (exclude == 0) return;

  switch (exclude) {
    case bC11: ui->bnC11->setEnabled(true); break;
    case bC12: ui->bnC12->setEnabled(true); break;
    case bC21: ui->bnC21->setEnabled(true); break;
    case bC22: ui->bnC22->setEnabled(true); break;
    case bC31: ui->bnC32->setEnabled(true); break;
    case bC32: ui->bnC32->setEnabled(true); break;
    default: break;
  }
}

void MainWindow::UnlockCmdKeys()
{
  ui->bnC11->setEnabled(true);
  ui->bnC12->setEnabled(true);
  ui->bnC21->setEnabled(true);
  ui->bnC22->setEnabled(true);
  ui->bnC31->setEnabled(true);
  ui->bnC32->setEnabled(true);
}

void MainWindow::on_bnC11_clicked()
{
  if (FormularFormOpened) return;

  objFormularForm = new FormularForm(ui->waForm);

  objFormularForm->ui->eDepot->setText(*Formular->Depot);
  objFormularForm->ui->eOperator->setText(*Formular->Operator);
  objFormularForm->ui->eLocomotive->setText(*Formular->Locomotive);
  objFormularForm->ui->eLeftWheelN->setText(*Formular->LeftWheelN);
  objFormularForm->ui->eLeftWheelD->setText(*Formular->LeftWheelD);
  objFormularForm->ui->eRightWheelN->setText(*Formular->RightWheelN);
  objFormularForm->ui->eRightWheelD->setText(*Formular->RightWheelD);
  objFormularForm->ui->eNotes->setPlaceholderText(*Formular->Notes);

  connect(objFormularForm, SIGNAL(FormularFormClosed(int)), this, SLOT(FormularFormClosed(int)));
  FormularFormOpened = true;
  objFormularForm->show();
  LockCmdKeys(0); UnlockKeyboard();
}

void MainWindow::on_bnC12_clicked()
{
  if (TurningFormOpened) return;

  objTurningForm = new TurningForm(ui->waForm);

  connect(objTurningForm, SIGNAL(TurningFormClosed(int)), this, SLOT(TurningFormClosed(int)));
  TurningFormOpened = true;
  objTurningForm->show();
  LockCmdKeys(0);LockKeyboardA();
}

void MainWindow::on_bnC31_clicked()
{
  this->close();
}

void MainWindow::on_bn101_clicked()
{
  AddLetter(ui->bn101->text());
}

void MainWindow::on_bn102_clicked()
{
  AddLetter(ui->bn102->text());
}

void MainWindow::on_bn103_clicked()
{
  AddLetter(ui->bn103->text());
}

void MainWindow::on_bn104_clicked()
{
  AddLetter(ui->bn104->text());
}

void MainWindow::on_bn105_clicked()
{
  AddLetter(ui->bn105->text());
}


void MainWindow::on_bn106_clicked()
{
  AddLetter(ui->bn106->text());
}

void MainWindow::on_bn107_clicked()
{
  AddLetter(ui->bn107->text());
}

void MainWindow::on_bn108_clicked()
{
  AddLetter(ui->bn108->text());
}

void MainWindow::on_bn109_clicked()
{
  AddLetter(ui->bn109->text());
}

void MainWindow::on_bn110_clicked()
{
  AddLetter(ui->bn110->text());
}

void MainWindow::on_bn111_clicked()
{
  AddLetter(ui->bn111->text());
}

void MainWindow::on_bn112_clicked()
{
  AddLetter(ui->bn112->text());
}

void MainWindow::on_bn113_clicked()
{
  AddLetter(ui->bn113->text());
}

void MainWindow::on_bn201_clicked()
{
  AddLetter(ui->bn201->text());
}

void MainWindow::on_bn202_clicked()
{
  AddLetter(ui->bn202->text());
}

void MainWindow::on_bn203_clicked()
{
  AddLetter(ui->bn203->text());
}

void MainWindow::on_bn204_clicked()
{
  AddLetter(ui->bn204->text());
}

void MainWindow::on_bn205_clicked()
{
  AddLetter(ui->bn205->text());
}

void MainWindow::on_bn206_clicked()
{
  AddLetter(ui->bn206->text());
}

void MainWindow::on_bn207_clicked()
{
  AddLetter(ui->bn207->text());
}

void MainWindow::on_bn208_clicked()
{
  AddLetter(ui->bn208->text());
}

void MainWindow::on_bn209_clicked()
{
  AddLetter(ui->bn209->text());
}

void MainWindow::on_bn210_clicked()
{
  AddLetter(ui->bn210->text());
}

void MainWindow::on_bn211_clicked()
{
  AddLetter(ui->bn211->text());
}

void MainWindow::on_bn212_clicked()
{
  AddLetter(ui->bn212->text());
}

void MainWindow::on_bn213_clicked()
{
  AddLetter(ui->bn213->text());
}

void MainWindow::on_bn301_clicked()
{
  AddLetter(ui->bn301->text());
}

void MainWindow::on_bn302_clicked()
{
  AddLetter(ui->bn302->text());
}

void MainWindow::on_bn303_clicked()
{
  AddLetter(ui->bn303->text());
}

void MainWindow::on_bn304_clicked()
{
  AddLetter(ui->bn304->text());
}

void MainWindow::on_bn305_clicked()
{
  AddLetter(ui->bn305->text());
}

void MainWindow::on_bn306_clicked()
{
  AddLetter(ui->bn306->text());
}

void MainWindow::on_bn307_clicked()
{
  AddLetter(ui->bn307->text());
}

void MainWindow::on_bn308_clicked()
{
  AddLetter(ui->bn308->text());
}

void MainWindow::on_bn309_clicked()
{
  AddLetter(ui->bn309->text());
}

void MainWindow::on_bn310_clicked()
{
  AddLetter(ui->bn310->text());
}

void MainWindow::on_bn311_clicked()
{
  AddLetter(ui->bn311->text());
}

void MainWindow::on_bn312_clicked()
{
  AddLetter(ui->bn312->text());
}

void MainWindow::on_bn313_clicked()
{
  AddLetter(ui->bn313->text());
}

void MainWindow::on_bn401_clicked()
{
  AddLetter(ui->bn401->text());
}

void MainWindow::on_bn402_clicked()
{
  AddLetter(ui->bn402->text());
}

void MainWindow::on_bn403_clicked()
{
  AddLetter(ui->bn403->text());
}

void MainWindow::on_bn404_clicked()
{
  AddLetter(ui->bn404->text());
}

void MainWindow::on_bn405_clicked()
{
  AddLetter(ui->bn405->text());
}

void MainWindow::on_bn406_clicked()
{
  AddLetter(ui->bn406->text());
}

void MainWindow::on_bn407_clicked()
{
  AddLetter(ui->bn407->text());
}

void MainWindow::on_bn408_clicked()
{
  AddLetter(ui->bn408->text());
}

void MainWindow::on_bn409_clicked()
{
  AddLetter(ui->bn409->text());
}

void MainWindow::on_bn410_clicked()
{
  AddLetter(ui->bn410->text());
}

void MainWindow::on_bn411_clicked()
{
  AddLetter(ui->bn411->text());
}

void MainWindow::on_bn412_clicked()
{
  AddLetter(ui->bn412->text());
}

void MainWindow::on_bn413_clicked()
{
  AddLetter(ui->bn413->text());
}

