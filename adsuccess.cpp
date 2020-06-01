#include "adsuccess.h"
#include "ui_adsuccess.h"
#include"user_search_book.h"
#include"mainwindow.h"


adsuccess::adsuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adsuccess)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin");
    this->setWindowState(Qt::WindowMaximized);

}

adsuccess::~adsuccess()
{
    delete ui;
}

void adsuccess::on_pushButton_adminbooklist_clicked()
{
    adbooklist = new admin_book_list(this);
    adbooklist->show();
}

void adsuccess::on_pushButton_adminaddbook_clicked()
{
    adbook =new admin_add_book(this);
    adbook->show();
}

void adsuccess::on_pushButton_2_clicked()
{
    adexbook = new admin_add_existing_book(this);
    adexbook->show();
}

void adsuccess::on_pushButton_admin_search_book_clicked()
{
   uss = new user_search_book(this);
   uss->show();
}

void adsuccess::on_pushButton_adminstatistics_clicked()
{
    stcs = new admin_see_statistics(this);
    stcs->show();
}

void adsuccess::on_pushButton_admin_delete_book_clicked()
{
    addelete = new admin_delete_book(this);
    addelete->show();
}

void adsuccess::on_pushButton_clicked()
{

}
