/**
 * @file CustomerWindows/ReturnOrderDialog.h
 * @brief ReturnOrderDialog.h — Header and declarations for the ReturnOrderDialog.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

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
/**
 * @brief Execute the function's primary operation.
 * @param infoText The infoText parameter used by the function.
 */

    void displayReceiptInfo(const QString& infoText);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param memento The memento parameter used by the function.
 */

    QString buildReceiptSummary(const OrderMemento* memento) const;
};

#endif
