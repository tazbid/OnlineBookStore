#include "admin_delete_book.h"
#include "ui_admin_delete_book.h"
#include"database.h"
#include<QMessageBox>

admin_delete_book::admin_delete_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_delete_book)
{
    ui->setupUi(this);
    this->setWindowTitle("Delete Book");
    this->setWindowState(Qt::WindowMaximized);

}

admin_delete_book::~admin_delete_book()
{
    delete ui;
}

void admin_delete_book::on_pushButton_delete_book_clicked()
{
    QString str;
    str= ui->lineEdit_delete_book->text();

    if(str == nullptr)
    {
        QMessageBox::critical(this,"Failed to delete Book!","Please enter the Book Id of the book you want to delete!");
    }
    else
    {
        database comm;
        comm.connOpen();
        QSqlQuery query1;
        query1.prepare("delete from table_booklist where Book_ID='"+str+"'  ");
        QSqlQuery query2;
        query2.prepare("delete from table_inventory where Book_ID='"+str+"'  ");
        if(query1.exec() && query2.exec())
        {
            QMessageBox::information(this,"Book Deleted!","Book Deleted Successfully");
            comm.connClose();
        }
        else
        {
            QMessageBox::critical(this,"Error qry1",query1.lastError().text());
            QMessageBox::critical(this,"Error qry2",query2.lastError().text());

        }

    }
}
