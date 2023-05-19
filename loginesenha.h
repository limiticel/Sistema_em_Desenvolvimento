#ifndef LOGINESENHA_H
#define LOGINESENHA_H
#include<QtSql>
#include<QFileInfo>
#include<QtDebug>
#include<QMessageBox>
#include <QMainWindow>
#include"menusys.h"
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class LogineSenha; }
QT_END_NAMESPACE

class LogineSenha : public QMainWindow
{
    Q_OBJECT

public:
    LogineSenha(QWidget *parent = nullptr);
    ~LogineSenha();

private slots:
    void on_Btn_Entrar_clicked();

    void on_Ver_Senha_stateChanged(int arg1);

private:
    Ui::LogineSenha *ui;
};
#endif // LOGINESENHA_H
