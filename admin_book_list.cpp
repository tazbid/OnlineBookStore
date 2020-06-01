#include "admin_book_list.h"
#include "ui_admin_book_list.h"
#include"database.h"

admin_book_list::admin_book_list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_book_list)
{
    ui->setupUi(this);
    this->setWindowTitle("Book List");
    this->setWindowState(Qt::WindowMaximized);

}

admin_book_list::~admin_book_list()
{
    delete ui;
}

void admin_book_list::on_pushButton_admin_book_list_clicked()
{
    database con;
    mod = new QSqlQueryModel();
    con.connOpen();
    qri = new QSqlQuery(con.mydb);
    qri->prepare("select *from table_booklist");
    qri->exec();
    mod->setQuery(*qri);
    ui->tableView_admin_book_list->setModel(mod);
    ui->tableView_admin_book_list->setColumnWidth(0,150);
    ui->tableView_admin_book_list->setColumnWidth(1,250);
    ui->tableView_admin_book_list->setColumnWidth(2,250);
    ui->tableView_admin_book_list->setColumnWidth(3,145);
    ui->tableView_admin_book_list->setColumnWidth(4,132);

    con.connClose();
    qDebug() << (mod->rowCount());

}
