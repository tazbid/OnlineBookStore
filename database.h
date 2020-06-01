#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include<QtSql>
#include<QFileInfo>
#include<QTableView>

namespace Ui {
class database;
}

class database : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        QString path=QDir(QCoreApplication::applicationDirPath()).filePath("book_shop.db");
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(path);

        if(!mydb.open())
        {
            qDebug() << ("Failed to connect to the database!");
            return  false;
        }
        else
        {
            qDebug() << ("Connected to the database successfully!");
            return true;
        }
    }

public:
    explicit database(QWidget *parent = nullptr);
    ~database();

private:
    Ui::database *ui;
    QSqlQueryModel *modal;
    QSqlQuery *qry1;
    QSqlQuery *qry2;
    QSqlQuery *qry3;
};

#endif // DATABASE_H
