#include "centralmonitoramento.h"
#include "ui_centralmonitoramento.h"

CentralMonitoramento::CentralMonitoramento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CentralMonitoramento)
{
    ui->setupUi(this);
}

CentralMonitoramento::~CentralMonitoramento()
{
    delete ui;
}
