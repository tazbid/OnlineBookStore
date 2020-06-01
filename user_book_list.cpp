#include "user_book_list.h"
#include "ui_user_book_list.h"
#include"database.h"

user_book_list::user_book_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_book_list)
{
    ui->setupUi(this);
    this->setWindowTitle("Book List");
    this->setWindowState(Qt::WindowMaximized);
}

user_book_list::~user_book_list()
{
    delete ui;
}

void user_book_list::on_pushButton_see_book_list_clicked()
{
    database conn;
    modal = new QSqlQueryModel();
    conn.connOpen();
    qry = new QSqlQuery(conn.mydb);
    qry->prepare("select *from table_booklist");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_user_book_list->setModel(modal);
    ui->tableView_user_book_list->setColumnWidth(0,150);
    ui->tableView_user_book_list->setColumnWidth(1,250);
    ui->tableView_user_book_list->setColumnWidth(2,250);
    ui->tableView_user_book_list->setColumnWidth(3,145);
    ui->tableView_user_book_list->setColumnWidth(4,132);


    conn.connClose();
    qDebug() << (modal->rowCount());
}

void user_book_list::on_pushButton_user_buybook_clicked()
{
    userbook = new user_buy_book(this);
    userbook->show();
}

void user_book_list::on_pushButton_user_search_book_clicked()
{
    usersearch = new user_search_book(this);
    usersearch->show();
}

void user_book_list::on_pushButton_2_clicked()
{
    usersearch = new user_search_book(this);
    usersearch->show();
}
