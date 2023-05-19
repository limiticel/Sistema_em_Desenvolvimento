#ifndef CADASTRO_H
#define CADASTRO_H
#include"menusys.h"
#include"loginesenha.h"
#include<QtSql>
#include<QFileInfo>
#include<QDebug>
#include<QMessageBox>
#include <QDialog>


namespace Ui {
class Cadastro;
}

class Cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit Cadastro(QWidget *parent = nullptr);
    ~Cadastro();

private slots:
    void on_Btn_Voltar_clicked();

    void on_Btn_Cadastrar_clicked();

    void on_Btn_Editar_clicked();

private:
    Ui::Cadastro *ui;
};

#endif // CADASTRO_H
