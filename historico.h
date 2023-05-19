#ifndef HISTORICO_H
#define HISTORICO_H

#include <QDialog>
#include<QtSql>
#include"vendas.h"
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class Historico;
}

class Historico : public QDialog
{
    Q_OBJECT

public:
    explicit Historico(QWidget *parent = nullptr);
    ~Historico();

private slots:
    void on_Btn_Voltar_clicked();

    void on_Btn_Pesquisar_clicked();

    void on_Btn_Sair_clicked();

private:
    Ui::Historico *ui;
};

#endif // HISTORICO_H
