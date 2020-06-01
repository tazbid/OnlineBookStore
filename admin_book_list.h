#ifndef ADMIN_BOOK_LIST_H
#define ADMIN_BOOK_LIST_H

#include <QDialog>
#include<QtSql>
#include<QFileInfo>
#include<QTableView>

namespace Ui {
class admin_book_list;
}

class admin_book_list : public QDialog
{
    Q_OBJECT

public:
    explicit admin_book_list(QWidget *parent = nullptr);
    ~admin_book_list();

private slots:
    void on_pushButton_admin_book_list_clicked();

private:
    Ui::admin_book_list *ui;
    QSqlQueryModel *mod;
    QSqlQuery *qri;

};

#endif // ADMIN_BOOK_LIST_H
