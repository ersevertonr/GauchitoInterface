#ifndef CENTRALMONITORAMENTO_H
#define CENTRALMONITORAMENTO_H

#include <QDialog>

namespace Ui {
class CentralMonitoramento;
}

class QUdpSocket;

class CentralMonitoramento : public QDialog
{
    Q_OBJECT

public:
    explicit CentralMonitoramento(QWidget *parent = 0);
    ~CentralMonitoramento();

private slots:
    void on_conectarbuffer_clicked();

private:
    Ui::CentralMonitoramento *ui;
    QUdpSocket *bufferSocket;
};

#endif // CENTRALMONITORAMENTO_H
