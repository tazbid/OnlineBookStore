#ifndef ADSUCCESS_H
#define ADSUCCESS_H

#include <QDialog>
#include"admin_add_book.h"
#include"admin_book_list.h"
#include"admin_add_existing_book.h"
#include"user_search_book.h"
#include"admin_see_statistics.h"
#include"admin_delete_book.h"



namespace Ui {
class adsuccess;
}

class adsuccess : public QDialog
{
    Q_OBJECT

public:
    explicit adsuccess(QWidget *parent = nullptr);
    ~adsuccess();

private slots:
    void on_pushButton_adminbooklist_clicked();

    void on_pushButton_adminaddbook_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_admin_search_book_clicked();

    void on_pushButton_adminstatistics_clicked();

    void on_pushButton_admin_delete_book_clicked();

    void on_pushButton_clicked();

private:
    Ui::adsuccess *ui;
    admin_add_book *adbook;
    admin_book_list *adbooklist;
    admin_add_existing_book *adexbook;
    user_search_book *uss;
    admin_see_statistics *stcs;
    admin_delete_book *addelete;

};

#endif // ADSUCCESS_H
