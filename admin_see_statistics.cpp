#include "admin_see_statistics.h"
#include "ui_admin_see_statistics.h"
#include"database.h"

admin_see_statistics::admin_see_statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_see_statistics)
{
    ui->setupUi(this);
    this->setWindowTitle("Statistics");
    this->setWindowState(Qt::WindowMaximized);

}

admin_see_statistics::~admin_see_statistics()
{
    delete ui;
}

void admin_see_statistics::on_pushButton_see_statistics_clicked()
{
    database cm;
    model = new QSqlQueryModel();
    cm.connOpen();
    qry = new QSqlQuery(cm.mydb);
    qry->prepare("select *from table_userdata");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView_statistics->setModel(model);
    ui->tableView_statistics->setColumnWidth(0,122);
    ui->tableView_statistics->setColumnWidth(1,122);
    ui->tableView_statistics->setColumnWidth(2,122);
    ui->tableView_statistics->setColumnWidth(3,120);
    ui->tableView_statistics->setColumnWidth(4,220);
    ui->tableView_statistics->setColumnWidth(5,220);

    cm.connClose();
    qDebug() << (model->rowCount());
}
