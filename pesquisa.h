#ifndef PESQUISA_H
#define PESQUISA_H
#include"menusys.h"
#include <QDialog>
#include<QtSql>
#include<QFileInfo>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class Pesquisa;
}

class Pesquisa : public QDialog
{
    Q_OBJECT

public:
    explicit Pesquisa(QWidget *parent = nullptr);
    ~Pesquisa();

private slots:
    void on_Btn_Voltar_clicked();

    void on_Btn_Excluir_clicked();

    void on_Btn_Pesquisa_clicked();

private:
    Ui::Pesquisa *ui;
};

#endif // PESQUISA_H
