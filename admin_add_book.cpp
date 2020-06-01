#include "admin_add_book.h"
#include "ui_admin_add_book.h"
#include<QString>
#include<QMessageBox>
#include"adsuccess.h"
#include"database.h"



admin_add_book::admin_add_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_add_book)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Book");
    this->setWindowState(Qt::WindowMaximized);
}

admin_add_book::~admin_add_book()
{
    delete ui;
}

void admin_add_book::on_pushButton_clicked()
{

    int quantity_int,price_int;
    //int book_name_int=0,writer_name_int=0;


    QString book_name, writer_name, price, qntity,line1,line2;
    book_name=ui->lineEdit_book_name->text();
    writer_name=ui->lineEdit_writer_name->text();
    price=ui->lineEdit_price->text();
    qntity=ui->lineEdit_quantity->text();

    quantity_int = qntity.toInt();
    price_int = price.toInt();







    if(book_name == nullptr || writer_name == nullptr || price == nullptr || qntity == nullptr)
    {
        QMessageBox::critical(this,"Failed!","Please enter all the information correctly.");

    }
    else if(quantity_int <= 0 || price_int <= 0)
    {
        QMessageBox::critical(this,"Failed to add book!","Book adding failed! Please enter all the information correctly.");
    }

    else
    {
        database *conn = new database;
        conn->connOpen();
        QSqlQuery qry1(conn->mydb);
        QSqlQuery qry2(conn->mydb);
        line1="insert into table_booklist (Book_Name,Writer,Price,Quantity) values ('"+book_name+"','"+writer_name+"','"+price+"','"+qntity+"')";
        line2="insert into table_inventory (Quantity) values ('"+qntity+"')";


        if(qry1.exec(line1) && qry2.exec(line2))
        {
            hide();
            adsuccess *newadsuccess = new adsuccess;
            newadsuccess->show();

            QMessageBox::information(this,tr("Info"),tr("New Book Added!"));
            qry1.prepare(line1);
            qry2.prepare(line2);
            conn->connClose();

        }
        else
        {
            QMessageBox::information(this,tr("Info"),qry1.lastError().text());
        }
    }


}
