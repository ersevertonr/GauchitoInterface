#include "centralmonitoramento.h"
#include "ui_centralmonitoramento.h"
#include <QUdpSocket>

#define QTDE_REG 30

typedef struct { QString valor;} Dado;
typedef struct { Dado vetor[QTDE_REG];} VetorDados;

VetorDados vDados;
QString buffer;

CentralMonitoramento::CentralMonitoramento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CentralMonitoramento)
{
    ui->setupUi(this);
    bufferSocket = new QUdpSocket(this);
    connect(bufferSocket, &QUdpSocket::readyRead, [&](){
        if (bufferSocket->hasPendingDatagrams()){
            QByteArray datagrama;
            datagrama.resize(bufferSocket->pendingDatagramSize());
            bufferSocket->readDatagram(datagrama.data(), datagrama.size());
            buffer = QString(datagrama);

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

            ui->labelTeste0->addItem(buffer);
            ui->labelTeste1->setText(QString(vDados.vetor[0].valor));

            ui->labelDadosUSDistanciaCm->setText(QString(vDados.vetor[1].valor));
            ui->labelDadosUSDistanciaPl->setText(QString(vDados.vetor[2].valor));

            ui->labelDadosSonarDistanciaCm->setText(QString(vDados.vetor[3].valor));
            ui->labelDadosSonarDistanciaPl->setText(QString(vDados.vetor[4].valor));

            ui->labelDadosGPSStatus->setText(QString(vDados.vetor[5].valor));
            ui->labelDadosGPSLatitude->setText(QString(vDados.vetor[6].valor));
            ui->labelDadosGPSLongitude->setText(QString(vDados.vetor[7].valor));

            ui->labelDadosIV1->setText(QString(vDados.vetor[8].valor));
            ui->labelDadosIV2->setText(QString(vDados.vetor[9].valor));
            ui->labelDadosIV3->setText(QString(vDados.vetor[10].valor));
            ui->labelDadosIV4->setText(QString(vDados.vetor[11].valor));
            ui->labelDadosIV5->setText(QString(vDados.vetor[12].valor));
            ui->labelDadosIV6->setText(QString(vDados.vetor[13].valor));

            ui->labelDadosBussolaSX->setText(QString(vDados.vetor[14].valor));
            ui->labelDadosBussolaSY->setText(QString(vDados.vetor[15].valor));

            ui->labelDadosMESinal->setText(QString(vDados.vetor[16].valor));
            ui->labelDadosMEDistancia->setText(QString(vDados.vetor[17].valor));
            ui->labelDadosMEVelocidade->setText(QString(vDados.vetor[18].valor));
            ui->labelDadosMDSinal->setText(QString(vDados.vetor[19].valor));
            ui->labelDadosMDDistancia->setText(QString(vDados.vetor[20].valor));
            ui->labelDadosMDVelocidade->setText(QString(vDados.vetor[21].valor));
            ui->labelDadosMDGDistancia->setText(QString(vDados.vetor[22].valor));
            ui->labelDadosMDGVelocidade->setText(QString(vDados.vetor[23].valor));

            for (int i = 0; i < buffer.size();i++){
                vDados.vetor[i].valor = " ";
            }
        }
    } );
}

CentralMonitoramento::~CentralMonitoramento()
{
    delete ui;
}

void CentralMonitoramento::on_conectarbuffer_clicked()
{
    bufferSocket->bind(12345,QUdpSocket::ShareAddress);
}
