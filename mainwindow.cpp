#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Our Online Bookshop");
    this->setWindowState(Qt::WindowMaximized);
    QPixmap pix("C:/Book Shop.tech ninjas/welcome.jpg");
    ui->label_intro->setPixmap(pix.scaled(1500,2000,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_admin_clicked()
{
    admini = new admin(this);
    admini->show();
}

void MainWindow::on_pushButton_buybook_clicked()
{
    ubooklist = new user_book_list(this);
    ubooklist->show();
}
