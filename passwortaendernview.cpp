#include "passwortaendernview.h"
#include "ui_passwortaendernview.h"

PasswortAendernView::PasswortAendernView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswortAendernView)
{
    ui->setupUi(this);
}

PasswortAendernView::~PasswortAendernView()
{
    delete ui;
}

void PasswortAendernView::on_change_password_button_clicked()
{

}
