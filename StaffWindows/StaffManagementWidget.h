/**
 * @file StaffWindows/StaffManagementWidget.h
 * @brief StaffManagementWidget.h — Header and declarations for the StaffManagementWidget.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef STAFFMANAGEMENTWIDGET_H
#define STAFFMANAGEMENTWIDGET_H

#include <QWidget>
#include "../GreenHouseFacade.h"

namespace Ui {
class StaffManagementWidget;
}

class StaffManagementWidget : public QWidget
{
    Q_OBJECT

public:
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    explicit StaffManagementWidget(QWidget *parent = nullptr);
    ~StaffManagementWidget();

private slots:
    void onRefreshQueueClicked();
    void onProcessQueueClicked();
    void onClearQueueClicked();
    void onAddWaterHandlerClicked();
    void onAddFertilizerHandlerClicked();
    void onAddDeadHandlerClicked();
    void onAddSalesHandlerClicked();
    void onRemoveHandlerClicked();
    void onRefreshHandlersClicked();
    void onHandlerSelectionChanged();

private:
    Ui::StaffManagementWidget *ui;
    GreenHouseFacade *facade;

    void setupConnections();
    void updateQueueDisplay();
    void updateHandlerDisplay();
    void updateSystemInfo();
    void loadHandlerTable();
};

#endif
