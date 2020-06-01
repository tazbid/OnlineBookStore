#ifndef ADMIN_DELETE_BOOK_H
#define ADMIN_DELETE_BOOK_H

#include <QDialog>

namespace Ui {
class admin_delete_book;
}

class admin_delete_book : public QDialog
{
    Q_OBJECT

public:
    explicit admin_delete_book(QWidget *parent = nullptr);
    ~admin_delete_book();

private slots:
    void on_pushButton_delete_book_clicked();

private:
    Ui::admin_delete_book *ui;
};

#endif // ADMIN_DELETE_BOOK_H
