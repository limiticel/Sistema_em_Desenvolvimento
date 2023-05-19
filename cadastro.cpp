#include "cadastro.h"
#include "ui_cadastro.h"

Cadastro::Cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    //Bd.setDatabaseName("C:/Users/user/Desktop/Projetos/C++/sys/untitled1/Banco De Dados/Bd");
}

Cadastro::~Cadastro()
{
    delete ui;
}

void Cadastro::on_Btn_Voltar_clicked()
{
    this->close();
    Menu me;
    me.setModal(true);
    me.exec();
}


void Cadastro::on_Btn_Cadastrar_clicked()
{
    QString Nome_prod=ui->Nome->text();
    QString Valor=ui->Valor->text();
    QString Qtd=ui->Qtd->text();




    QSqlQuery query;
    if(query.exec("select * from Produtos where Nome='"+Nome_prod+"'"))
    {
        int cont=0;
        while(query.next())
        {
            cont++;
        }
        if(cont>0)
        {
            QMessageBox::warning(this,"Erro","Produto já cadastrado");
        }
        else
        {
            QSqlQuery query2;
            query2.prepare("insert into Produtos(Nome, Valor, Quantidade) values ('"+Nome_prod+"','"+Valor+"','"+Qtd+"')");

            if(!query2.exec())
            {
                QMessageBox::warning(this,"ERRO","Nao salvo");

            }
            else
            {
                QMessageBox::information(this,"Salvo","Salvo");
                ui->Nome->clear();
                ui->Nome->setFocus();
                ui->Valor->clear();
                ui->Qtd->clear();
            }
        }
    }
    else
    {
        QMessageBox::information(this,"Erro","nao salvo");
        qDebug()<<query.lastError().text();
    }


}

void Cadastro::on_Btn_Editar_clicked()
{
    QString Nome=ui->Nome->text();
    QString Valor=ui->Valor->text();
    QString Qtd=ui->Qtd->text();


    QSqlQuery query;
    if(query.exec("select * from Produtos where Nome='"+Nome+"'"))
    {
        int cont=0;

        while(query.next())
        {
            cont++;
        }
        if(cont>0)
        {
            QSqlQuery query2;
            query2.prepare("UPDATE Produtos SET Valor='"+Valor+"',Quantidade='"+Qtd+"' WHERE Nome='"+Nome+"'");
            if(!query2.exec())
            {
                QMessageBox::warning(this,"ERRO","Nao salvo");
            }
            else
            {
                QMessageBox::information(this,"Salvo","Produto Editado");
                ui->Nome->clear();
                ui->Nome->setFocus();
                ui->Valor->clear();
                ui->Qtd->clear();
            }
        }    else
        {
            QMessageBox::information(this,"Erro","Produto não encotrado");
        }
    }

}
