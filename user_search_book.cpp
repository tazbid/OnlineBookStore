#include "user_search_book.h"
#include "ui_user_search_book.h"
#include"database.h"
#include<QMessageBox>

user_search_book::user_search_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_search_book)
{
    ui->setupUi(this);
    this->setWindowTitle("Search Book");
    this->setWindowState(Qt::WindowMaximized);
}

user_search_book::~user_search_book()
{
    delete ui;
}

void user_search_book::on_pushButton_user_search_book_clicked()
{
    QString book_name;
    book_name=ui->lineEdit_user_given_book_name->text();

    if(book_name == nullptr)
    {
        QMessageBox::critical(this,"Book Searching Failed!","Please Enter Book Name.");
        return;
    }


        database co;
        co.connOpen();
        QSqlQuery qry3;
        qry3.prepare("select * from table_booklist where Book_Name= '"+book_name+"'");
        if(qry3.exec())
        {
            while (qry3.next())
            {
                ui->lineEdit_user_book_id->setText(qry3.value(0).toString());
                ui->lineEdit_current_quantity->setText(qry3.value(4).toString());
                ui->lineEdit_price->setText(qry3.value(3).toString());
            }
            QString book_id;
            book_id=ui->lineEdit_user_book_id->text();
            if(book_id == nullptr)
            {
                QMessageBox::information(this,"Info","Sorry! Book not found. Please check the spelling of the book name or try again in a few days because the book is out of stock. Thank You.");
            }
            else
            {
                QMessageBox::information(this,"Info","Book Found!");
            }
            co.connClose();
        }
        else
        {
            QMessageBox::information(this,tr("Info"),qry3.lastError().text());
        }

}
