#include "user_buy_book.h"
#include "ui_user_buy_book.h"
#include"database.h"
#include<QMessageBox>
#include<QString>
#include"user_book_list.h"

user_buy_book::user_buy_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_buy_book)
{
    ui->setupUi(this);
    this->setWindowTitle("Buy Book Now!");
    this->setWindowState(Qt::WindowMaximized);
}

user_buy_book::~user_buy_book()
{
    delete ui;
}

void user_buy_book::on_pushButton_clicked()
{
    QString name,book_id,user_quantity,mobile;
    QString date_and_time= QDateTime::currentDateTime().toString();
    QString book_price,book_quantity;

    QString last_quantity_string,total_price_string;
    QString name_string;

    int user_quantity_int,mobile_int;
    int last_quantity_int, total_price_int;
    int book_price_int, book_quantity_int;
    //int name_int = 0;







    name= ui->lineEdit_user_given_name->text();
    book_id = ui->lineEdit_user_given_book_id->text();
    user_quantity = ui->lineEdit_user_given_book_quantity->text();
    mobile= ui->lineEdit_user_given_mobile_no->text();

    user_quantity_int= user_quantity.toInt();
    mobile_int= mobile.toInt();


    if(name==nullptr || book_id==nullptr || user_quantity==nullptr ||mobile==nullptr)
    {
        QMessageBox::critical(this,"Purchasing Failed!","Please enter all the information correctly!");
    }
    else if(user_quantity_int <= 0)
    {
        QMessageBox::critical(this,"Purchasing failed!","You have to buy at least one book!");
    }
    else if(mobile_int <=0)
    {
        QMessageBox::critical(this,"Purchasing failed!","Failed to buy book! Please enter all the information correctly.");
    }
    else
    {
        database com;
        com.connOpen();

        QSqlQuery qry;
        qry.prepare("select * from table_booklist where Book_ID = '"+book_id+"' ");

        if(qry.exec())
        {
            while(qry.next())
            {
                book_price = qry.value(3).toString();
                book_quantity=qry.value(4).toString();
            }
            if(book_price==nullptr && book_quantity==nullptr)
            {
                QMessageBox::critical(this,"Purchasing Failed!","No book found. Please enter the book id correctly.");
            }
            else
            {
                book_price_int= book_price.toInt();
                book_quantity_int= book_quantity.toInt();



                last_quantity_int = book_quantity_int - user_quantity_int;
                total_price_int = book_price_int * user_quantity_int;

                if(last_quantity_int < 0)
                {
                    QMessageBox::critical(this,"Purchasing Failed","It seems that you're trying to purchase more books than we have in stock. Sorry for the inconvenience. Please try again in a few days. Thank you.");
                }

                else
                {
                    last_quantity_string =QString::number(last_quantity_int);
                    total_price_string = QString::number(total_price_int);


                    QSqlQuery qry1;
                    qry1.prepare("update table_booklist set Quantity='"+last_quantity_string+"'  where Book_ID ='"+book_id+"' ");

                    QSqlQuery qry2;
                    qry2.prepare("update table_inventory set Quantity ='"+last_quantity_string+"' where Book_ID ='"+book_id+"'  ");

                    QSqlQuery qry3;
                    QString line3="insert into table_history (Book_ID,Date,Quantity,Total_Amount) values ('"+book_id+"' , '"+date_and_time+"', '"+user_quantity+"' , '"+total_price_string+"' ) ";

                    QSqlQuery qry4;
                    QString line4="insert into table_userdata (Book_ID,Quantity,Total_Amount,Name,Mobile) values ('"+book_id+"', '"+user_quantity+"', '"+total_price_string+"' ,'"+name+"', '"+mobile+"' ) ";

                    if(qry1.exec() && qry2.exec() && qry3.exec(line3) && qry4.exec(line4))
                    {
                        qry3.prepare(line3);
                        qry4.prepare(line4);
                        QMessageBox::information(this,"Purchase Complete!","Total price for the book(s) is '"+total_price_string+"'tk . Our customer care will be in touch with you shortly. Thank you for buying books from our onlineshop.");

                    }
                    else
                    {
                        QMessageBox::information(this,tr("Info qry1"),qry1.lastError().text());
                        QMessageBox::information(this,tr("Info qry2"),qry2.lastError().text());
                        QMessageBox::information(this,tr("Info qry3"),qry3.lastError().text());
                        QMessageBox::information(this,tr("Info qry4"),qry4.lastError().text());
                    }



                    com.connClose();
                }

            }
        }


        else
        {
            QMessageBox::information(this,tr("Info qry"),qry.lastError().text());
        }
    }








}
