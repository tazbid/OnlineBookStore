#ifndef ADMIN_ADD_BOOK_H
#define ADMIN_ADD_BOOK_H

#include <QDialog>
#include<QtSql>
#include<QFileInfo>

namespace Ui {
class admin_add_book;
}

class admin_add_book :public QDialog
{
    Q_OBJECT

public:
    explicit admin_add_book(QWidget *parent = nullptr);
    ~admin_add_book();

private slots:
    void on_pushButton_clicked();

private:
    Ui::admin_add_book *ui;

};

#endif // ADMIN_ADD_BOOK_H
