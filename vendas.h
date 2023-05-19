#ifndef VENDAS_H
#define VENDAS_H

#include<QtSql>
#include<QFileInfo>
#include<QDebug>
#include<QMessageBox>
#include <QDialog>
#include<ctime>
#include<string>
#include"menusys.h"
#include"historico.h"

namespace Ui {
class Vendas;
}

class Vendas : public QDialog
{
    Q_OBJECT

public:
    explicit Vendas(QWidget *parent = nullptr);
    ~Vendas();

private slots:
    void on_Btn_Adicionar_clicked();

    void on_Btn_Finalizar_clicked();

    void on_pushButton_clicked();

    void on_Voltar_clicked();

    void on_Btn_Historico_clicked();

private:
    Ui::Vendas *ui;
};

#endif // VENDAS_H
