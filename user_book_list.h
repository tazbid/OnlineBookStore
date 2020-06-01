#ifndef USER_BOOK_LIST_H
#define USER_BOOK_LIST_H

#include <QDialog>
#include<QtSql>
#include<QFileInfo>
#include<QTableView>
#include"user_buy_book.h"
#include"user_search_book.h"



namespace Ui {
class user_book_list;
}

class user_book_list : public QDialog
{
    Q_OBJECT


public:
    explicit user_book_list(QWidget *parent = nullptr);
    ~user_book_list();

private slots:
    void on_pushButton_see_book_list_clicked();

    void on_pushButton_user_buybook_clicked();

    void on_pushButton_user_search_book_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::user_book_list *ui;
    QSqlQueryModel *modal;
    QSqlQuery *qry;
    user_buy_book *userbook;
    user_search_book *usersearch;


};

#endif // USER_BOOK_LIST_H
