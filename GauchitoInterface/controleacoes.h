#ifndef CONTROLEACOES_H
#define CONTROLEACOES_H

#include <QDialog>

namespace Ui {
class ControleAcoes;
}

class ControleAcoes : public QDialog
{
    Q_OBJECT

public:
    explicit ControleAcoes(QWidget *parent = 0);
    ~ControleAcoes();

private:
    Ui::ControleAcoes *ui;
};

#endif // CONTROLEACOES_H
