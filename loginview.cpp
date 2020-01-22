#include "loginview.h"
#include "ui_loginview.h"

LoginView::LoginView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_login_button_clicked()
{

}

void LoginView::on_exit_button_clicked()
{
    this->close();
}
