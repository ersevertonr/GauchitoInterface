#ifndef CENTRALMONITORAMENTO_H
#define CENTRALMONITORAMENTO_H

#include <QDialog>

namespace Ui {
class CentralMonitoramento;
}

class CentralMonitoramento : public QDialog
{
    Q_OBJECT

public:
    explicit CentralMonitoramento(QWidget *parent = 0);
    ~CentralMonitoramento();

private:
    Ui::CentralMonitoramento *ui;
};

#endif // CENTRALMONITORAMENTO_H
