#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"admin.h"
#include"user_book_list.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_admin_clicked();

    void on_pushButton_buybook_clicked();

private:
    Ui::MainWindow *ui;
    admin *admini;
    user_book_list *ubooklist;
};

#endif // MAINWINDOW_H
