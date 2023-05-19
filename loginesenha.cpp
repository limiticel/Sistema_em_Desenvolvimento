#include "loginesenha.h"
#include "ui_loginesenha.h"
#include "menusys.h"
#include<QtWidgets>


static QSqlDatabase Banco_de_Dados=QSqlDatabase::addDatabase("QSQLITE");
LogineSenha::LogineSenha(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LogineSenha)
{
    ui->setupUi(this);

   ui->fundo->lower();



    Banco_de_Dados.setDatabaseName("C:/Users/user/Desktop/Projetos/C++/sistema astec/systema/Banco De Dados/Bd");
    if(!Banco_de_Dados.open()){
        QMessageBox::warning(this,"ERRO","Banco desconectado");
        qDebug()<<Banco_de_Dados.lastError().text();
    }
    ui->txt_Senha->setEchoMode(QLineEdit::Password);

}

LogineSenha::~LogineSenha()
{
    delete ui;
}


void LogineSenha::on_Btn_Entrar_clicked()
{
    QString Nome=ui->txt_Usuario->text();
    QString Senha=ui->txt_Senha->text();

    QSqlQuery query;
    if(query.exec("Select * from Usuarios where Usuario='"+Nome+"'and Senha='"+Senha+"'"))
    {
        int cont=0;
        while(query.next())
        {
            cont++;
        }
        if(cont>0)
        {
           this->close();
           Menu menu;
           menu.setModal(true);
           menu.exec();
         }
        else
          {
            ui->Informcao->setText("Usuario e/ou Senha incorreto/s.");

        }
    }

}


void LogineSenha::on_Ver_Senha_stateChanged(int arg1)
{
    int check=ui->Ver_Senha->isChecked();
    if(!check)
    {
        ui->txt_Senha->setEchoMode(QLineEdit::Password);
}
    else
    {
        ui->txt_Senha->setEchoMode(QLineEdit::Normal);
    }
}

