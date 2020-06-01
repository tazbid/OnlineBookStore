#include "admin_add_existing_book.h"
#include "ui_admin_add_existing_book.h"
#include"database.h"
#include<QMessageBox>
#include"adsuccess.h"

admin_add_existing_book::admin_add_existing_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_add_existing_book)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Book");
    this->setWindowState(Qt::WindowMaximized);

}

admin_add_existing_book::~admin_add_existing_book()
{
    delete ui;
}

void admin_add_existing_book::on_pushButton_admin_add_existing_book_clicked()
{
    QString book_id, admin_given_quantity,result_quantity,last_quantity_string;

    int admin_given_quantity_int,result_quantity_int,last_quantity_int;

    book_id = ui->lineEdit_admin_given_book_id->text();
    admin_given_quantity=ui->lineEdit_admin_given_book_quantity->text();

    admin_given_quantity_int = admin_given_quantity.toInt();

    if(book_id == nullptr || admin_given_quantity == nullptr)
    {
        QMessageBox::critical(this,"Book Adding Failed","Please enter all the information correctly!");
    }
    else if(admin_given_quantity_int <= 0)
    {
        QMessageBox::critical(this,"Failed to add book!","You have to add at least one book!");
    }
    else
    {
        database ob;
        ob.connOpen();

        QSqlQuery qry;
        qry.prepare("select * from table_booklist where Book_ID = '"+book_id+"' ");
        if(qry.exec())
        {
            while (qry.next())
            {
                result_quantity = qry.value(4).toString();
            }
            if(result_quantity == nullptr)
            {
                QMessageBox::critical(this,"Failed!","No book found! Please enter the book id correctly.");
            }
            else
            {
                result_quantity_int = result_quantity.toInt();
                last_quantity_int = result_quantity_int + admin_given_quantity_int;

                last_quantity_string= QString::number(last_quantity_int);

                QSqlQuery qry1;
                qry1.prepare("update table_booklist set Quantity='"+last_quantity_string+"' where Book_ID='"+book_id+"'  ");

                QSqlQuery qry2;
                qry2.prepare("update table_inventory set Quantity='"+last_quantity_string+"' where Book_ID='"+book_id+"'  ");

                if(qry1.exec() && qry2.exec())
                {
                    hide();
                    adsuccess *ads = new adsuccess(this);
                    ads->show();
                    QMessageBox::information(this,"Book Added.","Book Added Successfully!");
                }
                else
                {
                    QMessageBox::critical(this,tr("info qry1"),qry1.lastError().text());
                    QMessageBox::critical(this,tr("info qry2"),qry2.lastError().text());

                }
            }

        }

        else
        {
            QMessageBox::information(this,tr("INFO qry"),qry.lastError().text());
        }
    }


}
