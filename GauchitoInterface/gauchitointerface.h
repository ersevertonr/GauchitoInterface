#ifndef GAUCHITOINTERFACE_H
#define GAUCHITOINTERFACE_H

#include <QMainWindow>
#include "controleacoes.h"

namespace Ui {
class GauchitoInterface;
}

class QUdpSocket;

class GauchitoInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit GauchitoInterface(QWidget *parent = 0);
    ~GauchitoInterface();

private slots:
    void on_actionControles_triggered();

    void on_buttonConectar_clicked();

private:
    Ui::GauchitoInterface *ui;

    QUdpSocket *bufferSocket;

    ControleAcoes *janelaControleAcoes;

};

#endif // GAUCHITOINTERFACE_H
