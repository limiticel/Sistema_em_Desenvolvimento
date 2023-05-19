#include "menusys.h"
#include "ui_menusys.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_Btn_Cadastro_clicked()
{
    this->close();
    Cadastro cad;
    cad.setModal(true);
    cad.exec();
}


void Menu::on_Btn_Produtos_clicked()
{
    this->close();
    Pesquisa pesq;
    pesq.setModal(true);
    pesq.exec();

}


void Menu::on_Btn_Sair_clicked()
{
    this->close();
}


void Menu::on_Btn_Vendas_clicked()
{
    this->close();
    Vendas venda;
    venda.setModal(true);
    venda.exec();
}

