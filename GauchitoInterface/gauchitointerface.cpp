#include "gauchitointerface.h"
#include "ui_gauchitointerface.h"
#include "controleacoes.h"
#include <QUdpSocket>

#define QTDE_REG 30

typedef struct { QString valor;} Dado;
typedef struct { Dado vetor[QTDE_REG];} VetorDados;

VetorDados vDados;
QString buffer;
int ping = 0;

GauchitoInterface::GauchitoInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GauchitoInterface)
{
    ui->setupUi(this);
    bufferSocket = new QUdpSocket(this);
    connect(bufferSocket, &QUdpSocket::readyRead, [&](){
        if (bufferSocket->hasPendingDatagrams()){
            QByteArray datagrama;
            datagrama.resize(bufferSocket->pendingDatagramSize());
            bufferSocket->readDatagram(datagrama.data(), datagrama.size());
            buffer = QString(datagrama);
            ++ping;

            int val = 0, ordem = 0;
            for (int i = 0; i < buffer.size(); i++){
                if (buffer[i] != QChar('|')){
                    vDados.vetor[ordem].valor[val] = buffer[i];
                    ++val;
                } else {
                    val = 0;
                    ++ordem;
                }
            }

            QString wifiSinal;
            if (buffer.isNull()){
                wifiSinal = "OFFLINE";
            } else {
                wifiSinal = "ONLINE";
            }

            ui->labelDadosWifiSinal->setText(wifiSinal);
            ui->labelDadosWifiBuffer->addItem(buffer);
            ui->labelDadosMensRecebida->setNum(ping);

            ui->labelDadosUSDistanciaCm->setText(QString(vDados.vetor[0].valor));
            ui->labelDadosUSDistanciaPl->setText(QString(vDados.vetor[1].valor));

            ui->labelDadosSonarDistanciaCm->setText(QString(vDados.vetor[2].valor));
            ui->labelDadosSonarDistanciaPl->setText(QString(vDados.vetor[3].valor));

            ui->labelDadosGPSLock->setText(QString(vDados.vetor[4].valor));
            ui->labelDadosGPSLat->setText(QString(vDados.vetor[5].valor));
            ui->labelDadosGPSLon->setText(QString(vDados.vetor[6].valor));

            ui->labelDadosIV1->setText(QString(vDados.vetor[7].valor));
            ui->labelDadosIV2->setText(QString(vDados.vetor[8].valor));
            ui->labelDadosIV3->setText(QString(vDados.vetor[9].valor));
            ui->labelDadosIV4->setText(QString(vDados.vetor[10].valor));
            ui->labelDadosIV5->setText(QString(vDados.vetor[11].valor));
            ui->labelDadosIV6->setText(QString(vDados.vetor[12].valor));

            ui->labelDadosBussolaSX->setText(QString(vDados.vetor[13].valor));
            ui->labelDadosBussolaSY->setText(QString(vDados.vetor[14].valor));
            ui->labelDadosBussolaSZ->setText(QString(vDados.vetor[15].valor));

            ui->labelDadoslChA->setText(QString(vDados.vetor[16].valor));
            ui->labelDadoslChB->setText(QString(vDados.vetor[17].valor));
            ui->labelDadoslCounter->setText(QString(vDados.vetor[18].valor));
            ui->labelDadoslRotation->setText(QString(vDados.vetor[19].valor));
            ui->labelDadosrChA->setText(QString(vDados.vetor[20].valor));
            ui->labelDadosrChB->setText(QString(vDados.vetor[21].valor));
            ui->labelDadosrCounter->setText(QString(vDados.vetor[22].valor));
            ui->labelDadosrRotation->setText(QString(vDados.vetor[23].valor));

            ui->labelDadosMGVelocidade->setText(QString(vDados.vetor[24].valor));
            ui->labelDadosMGDistancia->setText(QString(vDados.vetor[25].valor));

            for (int i = 0; i < buffer.size();i++){
                vDados.vetor[i].valor = " ";
            }
        }
    } );
}

GauchitoInterface::~GauchitoInterface()
{
    delete ui;
}

void GauchitoInterface::on_actionControles_triggered()
{
    janelaControleAcoes = new ControleAcoes(this);
    janelaControleAcoes->show();
}

void GauchitoInterface::on_buttonConectar_clicked()
{
    bufferSocket->bind(ui->inputPorta->value(),QUdpSocket::ShareAddress);
}

