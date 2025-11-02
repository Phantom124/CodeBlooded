#ifndef RETURNORDERDIALOG_H
#define RETURNORDERDIALOG_H

#include <QDialog>
#include <QString>
class CustomerFacade;
class OrderMemento;

namespace Ui {
class ReturnOrderDialog;
}

class ReturnOrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReturnOrderDialog(QWidget *parent = nullptr);
    ~ReturnOrderDialog();

private slots:
    void onSearchReceiptClicked();
    void onConfirmReturnClicked();
    void onCancelClicked();

private:
    Ui::ReturnOrderDialog *ui;
    CustomerFacade *facade;
    OrderMemento *currentMemento;
    QString activeReceiptId;
    
    void setupConnections();
    void displayReceiptInfo(const QString& infoText);
    QString buildReceiptSummary(const OrderMemento* memento) const;
};

#endif
