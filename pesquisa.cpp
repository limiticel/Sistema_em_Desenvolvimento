#include "pesquisa.h"
#include "ui_pesquisa.h"

Pesquisa::Pesquisa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pesquisa)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from Produtos");

    if(query.exec())
    {

        ui->Tabela->setColumnCount(4);
        int cont=0;
        while(query.next())
        {
           ui->Tabela->insertRow(cont);
           ui->Tabela->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
           ui->Tabela->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
           ui->Tabela->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
           ui->Tabela->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));

           cont++;

        }

    }
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

Pesquisa::~Pesquisa()
{
    delete ui;
}

void Pesquisa::on_Btn_Voltar_clicked()
{
    this->close();
    Menu me;
    me.setModal(true);
    me.exec();
}


void Pesquisa::on_Btn_Excluir_clicked()
{
    int Linha=ui->Tabela->currentRow();//vai selecionar o valor onde esta clicado
    int codigo=ui->Tabela->item(Linha,0)->text().toInt();
    QSqlQuery query;
    query.prepare("delete from Produtos where Codigo="+QString::number(codigo));
    if(query.exec())
    {
        QMessageBox::information(this,"Deletado com sucesso","");
    }
    else
    {
        QMessageBox::warning(this,"Erro","");
    }

    ui->Tabela->removeRow(Linha);
}


void Pesquisa::on_Btn_Pesquisa_clicked()
{
    {
        QString busca=ui->txt_busca->text();

        int linhas=ui->Tabela->rowCount();


        for(int i;i<linhas;i++)
        {
            if(busca==ui->Tabela->item(i,1)->text())
            {
                ui->Tabela->selectRow(i);
                i=linhas;
            }



        }
}
}

