#include "gauchitointerface.h"
#include "ui_gauchitointerface.h"
#include "controleacoes.h"
#include "centralmonitoramento.h"

GauchitoInterface::GauchitoInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GauchitoInterface)
{
    ui->setupUi(this);

    ui->labelDadosWifiSinal->setText("OFFLINE");

}

GauchitoInterface::~GauchitoInterface()
{
    delete ui;
}

void GauchitoInterface::on_actionCentral_de_Monitoramento_triggered()
{
    janelaCentralMonitoramento = new CentralMonitoramento(this);
    janelaCentralMonitoramento->show();

//    CentralMonitoramento janelaCentralMonitoramento;
//    janelaCentralMonitoramento.setModal(true);
//    janelaCentralMonitoramento.exec();
}

void GauchitoInterface::on_actionControles_triggered()
{
    janelaControleAcoes = new ControleAcoes(this);
    janelaControleAcoes->show();

//    ControleAcoes janelaControleAcoes;
//    janelaControleAcoes.setModal(true);
//    janelaControleAcoes.exec();
}
