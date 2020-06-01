#ifndef ADMIN_ADD_EXISTING_BOOK_H
#define ADMIN_ADD_EXISTING_BOOK_H

#include <QDialog>

namespace Ui {
class admin_add_existing_book;
}

class admin_add_existing_book : public QDialog
{
    Q_OBJECT

public:
    explicit admin_add_existing_book(QWidget *parent = nullptr);
    ~admin_add_existing_book();

private slots:
    void on_pushButton_admin_add_existing_book_clicked();

private:
    Ui::admin_add_existing_book *ui;
};

#endif // ADMIN_ADD_EXISTING_BOOK_H
