#include "centralmonitoramento.h"
#include "ui_centralmonitoramento.h"
#include <QUdpSocket>

#define LABEL_SIZE 20

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
            ui->printabuffer->addItem(QString(datagrama));
//            ui->labelTeste->setText(QString(datagrama));
        }
    } );

/* ------------ MAPEAMENTO DAS VARIÁVEIS PARA AS LABELS -------------*/

    /* GPS */
    const char gpsSinal[LABEL_SIZE]         = "OFF";
    const char gpsLatitude[LABEL_SIZE]      = "00.00000000";
    const char gpsLongitude[LABEL_SIZE]     = "00.00000000";

    /* INFRAVERMELHO */
    const char iv1[LABEL_SIZE]              = "0.0001";
    const char iv2[LABEL_SIZE]              = "0.0002";
    const char iv3[LABEL_SIZE]              = "0.0003";
    const char iv4[LABEL_SIZE]              = "0.0004";
    const char iv5[LABEL_SIZE]              = "0.0005";
    const char iv6[LABEL_SIZE]              = "0.0006";

    /* SONAR */
    const char sonarSinal[LABEL_SIZE]       = "OFF";
    const char sonarDistancia[LABEL_SIZE]   = "0.0000";

    /* MOTORES */
    const char meSinal[LABEL_SIZE]          = "OFF";
    const char meDistancia[LABEL_SIZE]      = "0.0000";
    const char meVelocidade[LABEL_SIZE]     = "0.0000";

    const char mdSinal[LABEL_SIZE]          = "OFF";
    const char mdDistancia[LABEL_SIZE]      = "0.0000";
    const char mdVelocidade[LABEL_SIZE]     = "0.0000";

    const char mdgDistancia[LABEL_SIZE]     = "0.0000";
    const char mdgVelocidade[LABEL_SIZE]    = "0.0000";

    /* ULTRASSOM */
    const char usSinal[LABEL_SIZE]          = "OFF";
    const char usDistancia[LABEL_SIZE]      = "0.0000";

    /* BÚSSOLA */
    const int bussola                       = 40;

/* ------------------------------------------------------------------*/

    ui->labelDadosGPSStatus->setText(QString("%1").arg(gpsSinal));
    ui->labelDadosGPSLatitude->setText(QString("%1").arg(gpsLatitude));
    ui->labelDadosGPSLongitude->setText(QString("%1").arg(gpsLongitude));

    ui->labelDadosIV1->setText(QString("%1").arg(iv1));
    ui->labelDadosIV2->setText(QString("%1").arg(iv2));
    ui->labelDadosIV3->setText(QString("%1").arg(iv3));
    ui->labelDadosIV4->setText(QString("%1").arg(iv4));
    ui->labelDadosIV5->setText(QString("%1").arg(iv5));
    ui->labelDadosIV6->setText(QString("%1").arg(iv6));

    ui->labelDadosSonarSinal->setText(QString("%1").arg(sonarSinal));
    ui->labelDadosSonarDistancia->setText(QString("%1").arg(sonarDistancia));

    ui->labelDadosMESinal->setText(QString("%1").arg(meSinal));
    ui->labelDadosMEDistancia->setText(QString("%1").arg(meDistancia));
    ui->labelDadosMEVelocidade->setText(QString("%1").arg(meVelocidade));
    ui->labelDadosMDSinal->setText(QString("%1").arg(mdSinal));
    ui->labelDadosMDDistancia->setText(QString("%1").arg(mdDistancia));
    ui->labelDadosMDVelocidade->setText(QString("%1").arg(mdVelocidade));
    ui->labelDadosMDGDistancia->setText(QString("%1").arg(mdgDistancia));
    ui->labelDadosMDGVelocidade->setText(QString("%1").arg(mdgVelocidade));

    ui->labelDadosUSSinal->setText(QString("%1").arg(usSinal));
    ui->labelDadosUSDistancia->setText(QString("%1").arg(usDistancia));

    ui->labelDadosBussola->setValue(bussola);
}

CentralMonitoramento::~CentralMonitoramento()
{
    delete ui;
}

void CentralMonitoramento::on_conectarbuffer_clicked()
{
    bufferSocket->bind(12345,QUdpSocket::ShareAddress);
}
