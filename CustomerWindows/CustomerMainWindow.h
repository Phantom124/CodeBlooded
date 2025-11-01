#ifndef CUSTOMERMAINWINDOW_H
#define CUSTOMERMAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <vector>
#include "../CustomerFacade.h"
#include "../Plant.h"
#include "../PlantComponent.h"

namespace Ui {
class CustomerMainWindow;
}

class CustomerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerMainWindow(QWidget *parent = nullptr);
    ~CustomerMainWindow();

signals:
    void logoutRequested();

private slots:
    void onFilterChanged(int index);
    void onRefreshInventoryClicked();
    void onPlantSelected(QListWidgetItem *item);
    void onAddToCartClicked();
    void onRemoveFromCartClicked();
    void onDecorationCheckChanged();
    void onApplyDiscountClicked();
    void onDiscountCodeChanged(const QString &code);
    void onCheckoutClicked();
    void onClearCartClicked();
    void onReturnOrderClicked();
    
    // Window management
    void onLogoutClicked();

private:
    Ui::CustomerMainWindow *ui;
    CustomerFacade *facade;
    Plant *selectedPlant;
    
    // Helper functions
    void setupConnections();
    void loadInventory();
    void updatePlantDisplay();
    void updateCartDisplay();
    void updateTotalPrice();
    void updateDiscountStatus();
    Plant* getSelectedPlant();
    std::vector<CustomerFacade::DecorationType> gatherSelectedDecorations() const;
    void clearDecorationCheckboxes();
};

#endif
