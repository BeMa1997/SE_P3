#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QDialog>

namespace Ui {
class LoginView;
}

class LoginView : public QDialog
{
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

private slots:
    void on_login_button_clicked();

    void on_exit_button_clicked();

private:
    Ui::LoginView *ui;
};

#endif // LOGINVIEW_H
