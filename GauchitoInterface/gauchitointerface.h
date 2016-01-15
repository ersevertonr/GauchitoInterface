#ifndef GAUCHITOINTERFACE_H
#define GAUCHITOINTERFACE_H

#include <QMainWindow>
#include "centralmonitoramento.h"
#include "controleacoes.h"

namespace Ui {
class GauchitoInterface;
}

class GauchitoInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit GauchitoInterface(QWidget *parent = 0);
    ~GauchitoInterface();

private slots:
    void on_actionCentral_de_Monitoramento_triggered();

    void on_actionControles_triggered();

private:
    Ui::GauchitoInterface *ui;

    CentralMonitoramento *janelaCentralMonitoramento;
    ControleAcoes *janelaControleAcoes;

};

#endif // GAUCHITOINTERFACE_H
