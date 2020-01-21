#ifndef PASSWORTAENDERNVIEW_H
#define PASSWORTAENDERNVIEW_H

#include <QWidget>

namespace Ui {
class PasswortAendernView;
}

class PasswortAendernView : public QWidget
{
    Q_OBJECT

public:
    explicit PasswortAendernView(QWidget *parent = nullptr);
    ~PasswortAendernView();

private slots:
    void on_change_password_button_clicked();

private:
    Ui::PasswortAendernView *ui;
};

#endif // PASSWORTAENDERNVIEW_H
