#ifndef GAUCHITOINTERFACE_H
#define GAUCHITOINTERFACE_H

#include <QMainWindow>

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
};

#endif // GAUCHITOINTERFACE_H
