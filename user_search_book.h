#ifndef USER_SEARCH_BOOK_H
#define USER_SEARCH_BOOK_H

#include <QDialog>
#include<QtSql>
#include<QFileInfo>

namespace Ui {
class user_search_book;
}

class user_search_book : public QDialog
{
    Q_OBJECT

public:
    explicit user_search_book(QWidget *parent = nullptr);
    ~user_search_book();

private slots:
    void on_pushButton_user_search_book_clicked();

private:
    Ui::user_search_book *ui;
};

#endif // USER_SEARCH_BOOK_H
