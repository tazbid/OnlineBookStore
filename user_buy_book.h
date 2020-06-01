#ifndef USER_BUY_BOOK_H
#define USER_BUY_BOOK_H

#include <QDialog>

namespace Ui {
class user_buy_book;
}

class user_buy_book : public QDialog
{
    Q_OBJECT

public:
    explicit user_buy_book(QWidget *parent = nullptr);
    ~user_buy_book();

private slots:
    void on_pushButton_clicked();

private:
    Ui::user_buy_book *ui;
};

#endif // USER_BUY_BOOK_H
