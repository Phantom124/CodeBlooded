/**
 * @file CustomerWindows/CustomerMainWindow.h
 * @brief CustomerMainWindow.h — Header and declarations for the CustomerMainWindow.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    explicit CustomerMainWindow(QWidget *parent = nullptr);
    ~CustomerMainWindow();

signals:
    void logoutRequested();

private slots:
/**
 * @brief Execute the function's primary operation.
 * @param index The index parameter used by the function.
 */

    void onFilterChanged(int index);
    void onRefreshInventoryClicked();
/**
 * @brief Execute the function's primary operation.
 * @param *item TODO - describe parameter
 */

    void onPlantSelected(QListWidgetItem *item);
    void onAddToCartClicked();
    void onRemoveFromCartClicked();
    void onDecorationCheckChanged();
    void onApplyDiscountClicked();
/**
 * @brief Execute the function's primary operation.
 * @param &code TODO - describe parameter
 */

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
