#include "gauchitointerface.h"
#include "ui_gauchitointerface.h"
#include "controleacoes.h"
#include "centralmonitoramento.h"

GauchitoInterface::GauchitoInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GauchitoInterface)
{
    ui->setupUi(this);
}

GauchitoInterface::~GauchitoInterface()
{
    delete ui;
}

void GauchitoInterface::on_actionCentral_de_Monitoramento_triggered()
{
    CentralMonitoramento janelaCentralMonitoramento;
    janelaCentralMonitoramento.setModal(true);
    janelaCentralMonitoramento.exec();
}

void GauchitoInterface::on_actionControles_triggered()
{
    ControleAcoes janelaControleAcoes;
    janelaControleAcoes.setModal(true);
    janelaControleAcoes.exec();
}
