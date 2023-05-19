#include "historico.h"
#include "ui_historico.h"
#include <iostream>
using namespace std;

Historico::Historico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historico)
{
    ui->setupUi(this);
    ui->txt_Busca->setPlaceholderText("Insira a data pra busca aqui");
    QSqlQuery query;
    query.prepare("select * from Venda");

    if(query.exec())
    {
        ui->Tabela->setColumnCount(5);
        int cont=0;
        while(query.next())
        {
            ui->Tabela->insertRow(cont);
            ui->Tabela->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->Tabela->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->Tabela->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->Tabela->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->Tabela->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
            cont++;
        }

    }

    ui->Tabela->setColumnCount(5);
    ui->Tabela->setColumnWidth(0,80);
    ui->Tabela->setColumnWidth(1,80);
    ui->Tabela->setColumnWidth(2,80);
    ui->Tabela->setColumnWidth(3,80);
    ui->Tabela->setColumnWidth(4,120);
    QStringList cabecalhos={"Item","Quantidade","Valor","data","Nome"};
    ui->Tabela->setHorizontalHeaderLabels(cabecalhos);
    ui->Tabela->verticalHeader()->hide();
    ui->Tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->Tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Historico::~Historico()
{
    delete ui;

}

void Historico::on_Btn_Voltar_clicked()
{
    this->close();
    Vendas ve;
    ve.setModal(true);
    ve.exec();

}


void Historico::on_Btn_Pesquisar_clicked()
{
    QString busca=ui->txt_Busca->text();

    int linhas=ui->Tabela->rowCount();


    for(int i;i<linhas;i++)
    {
        if(busca==ui->Tabela->item(i,3)->text())
        {
            ui->Tabela->selectRow(i);
            i=linhas;
        }



    }
}


void Historico::on_Btn_Sair_clicked()
{
    this->close();
}

