#ifndef CHANGEPASSWORDWINDOW_H
#define CHANGEPASSWORDWINDOW_H

#include <QDialog>

namespace Ui {
class changepasswordwindow;
}

class changepasswordwindow : public QDialog
{
    Q_OBJECT

public:
    explicit changepasswordwindow(QWidget *parent = nullptr);
    ~changepasswordwindow();
    void setId(int id);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::changepasswordwindow *ui;
    int id;
};

#endif // CHANGEPASSWORDWINDOW_H
