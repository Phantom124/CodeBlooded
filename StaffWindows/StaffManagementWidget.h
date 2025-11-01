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
