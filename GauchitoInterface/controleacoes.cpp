#include "controleacoes.h"
#include "ui_controleacoes.h"

ControleAcoes::ControleAcoes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControleAcoes)
{
    ui->setupUi(this);
}

ControleAcoes::~ControleAcoes()
{
    delete ui;
}
