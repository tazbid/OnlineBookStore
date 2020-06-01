#ifndef ADMIN_SEE_STATISTICS_H
#define ADMIN_SEE_STATISTICS_H

#include <QDialog>
#include<QtSql>
#include<QFileInfo>
#include<QTableView>

namespace Ui {
class admin_see_statistics;
}

class admin_see_statistics : public QDialog
{
    Q_OBJECT

public:
    explicit admin_see_statistics(QWidget *parent = nullptr);
    ~admin_see_statistics();

private slots:
    void on_pushButton_see_statistics_clicked();

private:
    Ui::admin_see_statistics *ui;
    QSqlQueryModel *model;
    QSqlQuery *qry;
};

#endif // ADMIN_SEE_STATISTICS_H
