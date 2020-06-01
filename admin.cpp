#include "admin.h"
#include "ui_admin.h"
#include<QPixmap>
#include<QMessageBox>

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin");
    this->setWindowState(Qt::WindowMaximized);
    QPixmap pix("C:/Book Shop.tech ninjas/admin.png");
    ui->label_admin->setPixmap(pix.scaled(220,220,Qt::KeepAspectRatio));
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_adlogin_clicked()
{
    QString username =ui->lineEdit_adusername->text();
    QString password =ui->lineEdit_adpassword->text();
    if((username =="admin" || username =="ADMIN") && (password =="admin" || password=="ADMIN"))
    {
        //hide();
        asuccess = new adsuccess(this);
        asuccess->show();
    }
    else {
        QMessageBox::critical(this,"Log-in Failed!","Incorrect Username or Password.Please try again.");
    }


}
