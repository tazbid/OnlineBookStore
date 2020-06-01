#include "adseebooklist.h"
#include "ui_adseebooklist.h"

adseebooklist::adseebooklist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adseebooklist)
{
    ui->setupUi(this);
    this->setWindowTitle("Book List");
    this->setWindowState(Qt::WindowMaximized);

}

adseebooklist::~adseebooklist()
{
    delete ui;
}
