#ifndef MENUSYS_H
#define MENUSYS_H
#include"cadastro.h"
#include"pesquisa.h"
#include"vendas.h"
#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_Btn_Cadastro_clicked();

    void on_Btn_Produtos_clicked();

    void on_Btn_Sair_clicked();

    void on_Btn_Vendas_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENUSYS_H
