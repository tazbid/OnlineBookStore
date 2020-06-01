#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include"adsuccess.h"

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_adlogin_clicked();

private:
    Ui::admin *ui;
    adsuccess *asuccess;

};

#endif // ADMIN_H
