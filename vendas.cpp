#include "vendas.h"
#include "ui_vendas.h"
#include<iostream>


using namespace std;


using namespace std;
Vendas::Vendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vendas)
{


    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from Produtos");

    if(query.exec())
    {

        ui->Tabela->setColumnCount(4);

    ui->Tabela->setColumnWidth(0,60);
    ui->Tabela->setColumnWidth(1,70);
    ui->Tabela->setColumnWidth(2,60);
    ui->Tabela->setColumnWidth(3,80);
    QStringList cabecalhos={"Codigo","Nome","Valor","Quantidade"};
    ui->Tabela->setHorizontalHeaderLabels(cabecalhos);
    ui->Tabela->verticalHeader()->hide();
    ui->Tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);//desativa a edição diretamente pela tabela
    ui->Tabela->setSelectionBehavior(QAbstractItemView::SelectRows);//linha inteira selelcionada quando clicada
    ui->Tabela->setStyleSheet("QTableView {selection-background-color=blue}");

 }
    static QString lista[50];

}

Vendas::~Vendas()
{
    delete ui;
}



void Vendas::on_Btn_Adicionar_clicked()
{

    QString Nome=ui->Prod->text();
    int row=ui->Tabela->rowCount();
    int lin=0;


    QSqlQuery query;
    query.prepare("select * from Produtos where Nome='"+Nome+"'");
    if(query.exec())
    {int cont=0;
     int conta=0;
     while(query.next()){cont++;}

       if(cont>0)
       {
       QSqlQuery query2;
       query2.exec("Select * from Produtos where Nome='"+Nome+"'");
        QString Nome=ui->Prod->text();
        QString Qtd=ui->Quantidade->text();
        if(Qtd==""){Qtd='1';}

        ui->Tabela->insertRow(0);
        int linhas=ui->Tabela->rowCount();
        int cont=0;
        static double val=0;

        QSqlQuery query3;
        query3.exec("Select * from Produtos where Nome='"+Nome+"'");

        if(query3.exec()&&query3.next())
           {
                  ui->Tabela->setItem(cont,0,new QTableWidgetItem(query3.value(0).toString()));
                  ui->Tabela->setItem(cont,1,new QTableWidgetItem(query3.value(1).toString()));
                  ui->Tabela->setItem(cont,2, new QTableWidgetItem(query3.value(2).toString()));
                  ui->Tabela->setItem(cont,3,new QTableWidgetItem(Qtd));
                  cont++;
                  val=query2.value(2).toDouble()+val;

                 /* QString Nome=ui->Tabela->item(0,1)->text();
                  QString lin=QString::number(linhas);
                  QString valor=QString::number(val);*/
           }else{QMessageBox::information(this,"","Erro");}

     ui->Prod->setFocus();
     ui->Quantidade->clear();}else{QMessageBox::information(this,"erro","Produto nao cadastrado.");}
      }

    double total=0;
    int linhas=ui->Tabela->rowCount();
    for(int i=0;i<linhas;i++){
        total+=ui->Tabela->item(i,2)->text().toDouble()*ui->Tabela->item(i,3)->text().toDouble();
        std::cout<<total<<std::endl;}
    QString valor=QString::number(total);
    ui->Total->setText(valor);
}



void Vendas::on_Btn_Finalizar_clicked()
{
    double total=0;
    int linhas=ui->Tabela->rowCount();

    for(int i=0;i<linhas;i++){
        total+=ui->Tabela->item(i,2)->text().toDouble()*ui->Tabela->item(i,3)->text().toDouble();
        std::cout<<total<<std::endl;}

    int cont=0;

    for(int i=0;i<linhas;i++)
    {
            time_t now=time(nullptr);
            struct tm timeinfo= *localtime(&now);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%d/%m/%Y", &timeinfo);
            QString data_atual=buffer;

            QString Nome_prod=ui->Tabela->item(i,1)->text();
            QString Valor=ui->Tabela->item(i,2)->text();
            QString Qtd=ui->Tabela->item(i,3)->text();
            QString Cliente=ui->txt_Cliente->text();
            int valor=Qtd.toInt();
            QSqlQuery query;
            query.prepare("insert into Venda(item, Valor, Quantidade, data,Nome) values ('"+Nome_prod+"','"+Valor+"','"+Qtd+"','"+data_atual+"','"+Cliente+"')");
            if(query.exec())
            {
                cont++;QSqlQuery busca;

                if(busca.exec("select * from Produtos where Nome='"+Nome_prod+"'"))
                {
                    while(busca.next()){
                    QSqlQuery atualizar;
                    int val=busca.value(3).toInt();
                    int cal=val-valor;


                    QString q=QString::number(cal);
                    atualizar.prepare("UPDATE Produtos SET Quantidade ='"+q+"' WHERE Nome ='"+Nome_prod+"'");
                    atualizar.exec();}


                }


            }
            else
            {
                qDebug()<<query.lastError().text();
            }
    }
    if(cont>0)
    {
        QMessageBox::information(this,"","Venda concluida");

    }
   for(int i=0;i<linhas;i++){ui->Tabela->removeRow(i);}
   ui->Tabela->removeRow(0);
   ui->txt_Cliente->clear();
   ui->Total->clear();



}



void Vendas::on_pushButton_clicked()
{
    int Linha=ui->Tabela->currentRow();//vai selecionar o valor onde esta clicado
    double valor=0;
    double item=ui->Tabela->item(Linha,2)->text().toDouble()*ui->Tabela->item(Linha,3)->text().toInt();
    int linhas=ui->Tabela->rowCount();
    for(int i=0;i<linhas;i++)
    {
       valor+=ui->Tabela->item(i,2)->text().toDouble()*ui->Tabela->item(i,3)->text().toInt();
    }
    qDebug()<<Linha;
    qDebug()<<item;
    qDebug()<<valor;
    valor=valor-item;
    QString val=QString::number(valor);

    ui->Total->setText(val);

    ui->Tabela->removeRow(Linha);
}


void Vendas::on_Voltar_clicked()
{
    this->close();
    Menu menu;
    menu.setModal(true);
    menu.exec();
}


void Vendas::on_Btn_Historico_clicked()
{
    this->close();
    Historico h;
    h.setModal(true);
    h.exec();
}

