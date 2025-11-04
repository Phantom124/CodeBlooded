/**
 * @file CustomerWindows/CustomerMainWindow.cpp
 * @brief CustomerMainWindow.cpp — Header and declarations for the CustomerMainWindow.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "CustomerMainWindow.h"
#include "ui_CustomerMainWindow.h"
#include "ReturnOrderDialog.h"
#include "ReceiptDialog.h"
#include "../Common/SharedInstances.h"
#include <QMessageBox>
#include <QStringList>

CustomerMainWindow::CustomerMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CustomerMainWindow)
    , facade(g_customerFacade)
    , selectedPlant(nullptr)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);
    setupConnections();
    loadInventory();
    updateCartDisplay();
    
/**
 * @brief Execute the function's primary operation.
 * @param Portal" TODO - describe parameter
 */

    setWindowTitle("Plant Nursery - Customer Portal");
}

CustomerMainWindow::~CustomerMainWindow()
{
    delete ui;
}

void CustomerMainWindow::setupConnections()
{
    // Plant browsing
    connect(ui->plantTypeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
        this, &CustomerMainWindow::onFilterChanged);
    connect(ui->maturityCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
        this, &CustomerMainWindow::onFilterChanged);
/**
 * @brief Execute the function's primary operation.
 * @param ui->refreshButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onRefreshInventoryClicked TODO - describe parameter
 */

    connect(ui->refreshButton, &QPushButton::clicked, this, &CustomerMainWindow::onRefreshInventoryClicked);
    
    // Plant selection
/**
 * @brief Execute the function's primary operation.
 * @param ui->inventoryList TODO - describe parameter
 * @param &QListWidget::itemClicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onPlantSelected TODO - describe parameter
 */

    connect(ui->inventoryList, &QListWidget::itemClicked, this, &CustomerMainWindow::onPlantSelected);
/**
 * @brief Execute the function's primary operation.
 * @param ui->addToCartButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onAddToCartClicked TODO - describe parameter
 */

    connect(ui->addToCartButton, &QPushButton::clicked, this, &CustomerMainWindow::onAddToCartClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->removeFromCartButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onRemoveFromCartClicked TODO - describe parameter
 */

    connect(ui->removeFromCartButton, &QPushButton::clicked, this, &CustomerMainWindow::onRemoveFromCartClicked);
    
    // Decorations
/**
 * @brief Execute the function's primary operation.
 * @param ui->redPotCheck TODO - describe parameter
 * @param &QCheckBox::stateChanged TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onDecorationCheckChanged TODO - describe parameter
 */

    connect(ui->redPotCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
/**
 * @brief Execute the function's primary operation.
 * @param ui->ribbonCheck TODO - describe parameter
 * @param &QCheckBox::stateChanged TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onDecorationCheckChanged TODO - describe parameter
 */

    connect(ui->ribbonCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
/**
 * @brief Execute the function's primary operation.
 * @param ui->scentCheck TODO - describe parameter
 * @param &QCheckBox::stateChanged TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onDecorationCheckChanged TODO - describe parameter
 */

    connect(ui->scentCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
/**
 * @brief Execute the function's primary operation.
 * @param ui->giftWrapCheck TODO - describe parameter
 * @param &QCheckBox::stateChanged TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onDecorationCheckChanged TODO - describe parameter
 */

    connect(ui->giftWrapCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
    
    // Discount
/**
 * @brief Execute the function's primary operation.
 * @param ui->applyDiscountButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onApplyDiscountClicked TODO - describe parameter
 */

    connect(ui->applyDiscountButton, &QPushButton::clicked, this, &CustomerMainWindow::onApplyDiscountClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->discountCodeEdit TODO - describe parameter
 * @param &QLineEdit::textChanged TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onDiscountCodeChanged TODO - describe parameter
 */

    connect(ui->discountCodeEdit, &QLineEdit::textChanged, this, &CustomerMainWindow::onDiscountCodeChanged);
    
    // Order management
/**
 * @brief Execute the function's primary operation.
 * @param ui->checkoutButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onCheckoutClicked TODO - describe parameter
 */

    connect(ui->checkoutButton, &QPushButton::clicked, this, &CustomerMainWindow::onCheckoutClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->clearCartButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onClearCartClicked TODO - describe parameter
 */

    connect(ui->clearCartButton, &QPushButton::clicked, this, &CustomerMainWindow::onClearCartClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->returnOrderButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onReturnOrderClicked TODO - describe parameter
 */

    connect(ui->returnOrderButton, &QPushButton::clicked, this, &CustomerMainWindow::onReturnOrderClicked);
    
    // Window management
/**
 * @brief Execute the function's primary operation.
 * @param ui->logoutButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &CustomerMainWindow::onLogoutClicked TODO - describe parameter
 */

    connect(ui->logoutButton, &QPushButton::clicked, this, &CustomerMainWindow::onLogoutClicked);
}

void CustomerMainWindow::loadInventory()
{
    ui->inventoryList->clear();
    selectedPlant = nullptr;
    
    if (!facade) return;
    
    // Get plants from inventory via facade
    std::vector<Plant*> plants = facade->browsePlants();
    
    for (Plant* plant : plants)
    {
        QString itemText = QString("%1 - %2 (R%3)")
            .arg(QString::fromStdString(plant->getName()))
            .arg(QString::fromStdString(plant->getMaturityStateName()))
/**
 * @brief Execute the function's primary operation.
 * @param plant->getPrice() TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

            .arg(plant->getPrice(), 0, 'f', 2);
        
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param itemText The itemText parameter used by the function.
 */

        QListWidgetItem *item = new QListWidgetItem(itemText);
/**
 * @brief Execute the function's primary operation.
 * @param Qt::UserRole TODO - describe parameter
 * @param QVariant::fromValue(static_cast<void*>(plant)) TODO - describe parameter
 */

        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<void*>(plant)));
/**
 * @brief Execute the function's primary operation.
 * @param item The item parameter used by the function.
 */

        ui->inventoryList->addItem(item);
    }
    
    updatePlantDisplay();
}

void CustomerMainWindow::onFilterChanged(int index)
{
/**
 * @brief Execute the function's primary operation.
 * @param index The index parameter used by the function.
 */

    Q_UNUSED(index);
    updatePlantDisplay();
}

void CustomerMainWindow::onRefreshInventoryClicked()
{
    loadInventory();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Refresh" TODO - describe parameter
 * @param successfully!" TODO - describe parameter
 */

    QMessageBox::information(this, "Refresh", "Inventory refreshed successfully!");
}

void CustomerMainWindow::onPlantSelected(QListWidgetItem *item)
{
    if (!item) return;
    
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param item->data(Qt::UserRole).value<void*>() TODO - describe parameter
 */

    Plant *plant = static_cast<Plant*>(item->data(Qt::UserRole).value<void*>());
    selectedPlant = plant;
    
    if (!plant) return;
    
    // Display plant details
    QString details = QString(
        "Plant Type: %1\n"
        "Maturity: %2\n"
        "Price: R%3\n"
        "Health: %4\n"
        "Water Level: %5\n"
        "Fertilizer Level: %6\n"
        "Water State: %7\n"
        "Fertilizer State: %8"
    ).arg(QString::fromStdString(plant->getName()))
     .arg(QString::fromStdString(plant->getMaturityStateName()))
     .arg(plant->getPrice())
     .arg(plant->getHealth())
     .arg(plant->getWaterLevel())
     .arg(plant->getFertilizerLevel())
     .arg(QString::fromStdString(plant->getWaterStateName()))
/**
 * @brief Execute the function's primary operation.
 * @param QString::fromStdString(plant->getFertilizerStateName()) TODO - describe parameter
 */

     .arg(QString::fromStdString(plant->getFertilizerStateName()));
    
/**
 * @brief Execute the function's primary operation.
 * @param details The details parameter used by the function.
 */

    ui->plantDetailsText->setPlainText(details);
}

void CustomerMainWindow::onAddToCartClicked()
{
    Plant *plant = getSelectedPlant();
    if (!plant)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Selection" TODO - describe parameter
 * @param inventory." TODO - describe parameter
 */

        QMessageBox::warning(this, "No Selection", "Please select a plant from inventory.");
        return;
    }
    
    if (!facade) return;
    
    const auto decorations = gatherSelectedDecorations();
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 * @param decorations The decorations parameter used by the function.
 */

    facade->addPlantToOrder(plant, decorations);
    
    loadInventory();
    updateCartDisplay();
    updateDiscountStatus();
    clearDecorationCheckboxes();
    
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param "Success" TODO - describe parameter
 * @param cart!" TODO - describe parameter
 */

    QMessageBox::information(this, "Success", "Plant added to cart!");
}

void CustomerMainWindow::onRemoveFromCartClicked()
{
    int currentRow = ui->cartList->currentRow();
    if (currentRow < 0)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Selection" TODO - describe parameter
 * @param cart." TODO - describe parameter
 */

        QMessageBox::warning(this, "No Selection", "Please select an item to remove from cart.");
        return;
    }
    
    if (!facade) return;
    
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param currentRow The currentRow parameter used by the function.
 */

    QListWidgetItem* item = ui->cartList->item(currentRow);
    if (!item)
    {
        return;
    }


    Plant* plant = static_cast<Plant*>(item->data(Qt::UserRole).value<void*>());
    if (plant)
    {
/**
 * @brief Execute the function's primary operation.
 * @param plant The plant parameter used by the function.
 */

        facade->removeFromOrder(plant);
    }

    loadInventory();
    updateCartDisplay();
    updateDiscountStatus();
}

void CustomerMainWindow::onDecorationCheckChanged()
{
    updateTotalPrice();
}

void CustomerMainWindow::onApplyDiscountClicked()
{
    if (!facade) return;
    
    QString code = ui->discountCodeEdit->text().trimmed().toUpper();
    
    if (code == "SAVE10" || code == "BULK")
    {
/**
 * @brief Execute the function's primary operation.
 * @param true The true parameter used by the function.
 * @param code.toStdString() TODO - describe parameter
 */

        facade->applyDiscount(true, code.toStdString());
        updateTotalPrice();
        updateDiscountStatus();
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Applied" TODO - describe parameter
 * @param order!" TODO - describe parameter
 */

        QMessageBox::information(this, "Discount Applied", "10% discount has been applied to your order!");
    }
    else if (code.isEmpty())
    {
/**
 * @brief Execute the function's primary operation.
 * @param false The false parameter used by the function.
 */

        facade->applyDiscount(false);
        updateTotalPrice();
        updateDiscountStatus();
    }
    else
    {


        facade->applyDiscount(false);
        updateTotalPrice();
/**
 * @brief Execute the function's primary operation.
 * @param applied)" TODO - describe parameter
 */

        ui->discountStatusLabel->setText("Invalid discount code (no discount applied)");
/**
 * @brief Execute the function's primary operation.
 * @param #b71c1c;" TODO - describe parameter
 */

        ui->discountStatusLabel->setStyleSheet("color: #b71c1c;");
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Code" TODO - describe parameter
 * @param 'BULK'." TODO - describe parameter
 */

        QMessageBox::warning(this, "Invalid Code", "Invalid discount code. Try 'SAVE10' or 'BULK'.");
    }
}

void CustomerMainWindow::onDiscountCodeChanged(const QString &code)
{
    if (!facade)
    {
        return;
    }

    if (code.trimmed().isEmpty() && facade->hasManualDiscount())
    {


        facade->applyDiscount(false);
    }

    updateTotalPrice();
    updateDiscountStatus();
}

void CustomerMainWindow::onCheckoutClicked()
{
    if (!facade || facade->getOrderItemCount() == 0)
    {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Cart" TODO - describe parameter
 * @param checkout." TODO - describe parameter
 */

        QMessageBox::warning(this, "Empty Cart", "Your cart is empty. Add items before checkout.");
        return;
    }
    
    Receipt* receipt = facade->checkout();
    
    if (receipt)
    {
        QString receiptText = QString(
            "Receipt ID: %1\n\n%2"
        ).arg(QString::fromStdString(receipt->getReceiptID()))
/**
 * @brief Execute the function's primary operation.
 * @param QString::fromStdString(receipt->getOrderInfo()) TODO - describe parameter
 */

         .arg(QString::fromStdString(receipt->getOrderInfo()));
        
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Complete" TODO - describe parameter
 * @param receiptText The receiptText parameter used by the function.
 */

        QMessageBox::information(this, "Purchase Complete", receiptText);
        
        delete receipt;
        
        ui->discountCodeEdit->clear();
        loadInventory();
        updateCartDisplay();
        updateDiscountStatus();
        updateTotalPrice();
    }
}

void CustomerMainWindow::onClearCartClicked()
{
    if (QMessageBox::question(this, "Clear Cart", "Are you sure you want to clear the cart?") 
        == QMessageBox::Yes)
    {
        if (facade)
        {
            facade->clearOrder();
        }
        loadInventory();
        updateCartDisplay();
        ui->discountCodeEdit->clear();
        updateDiscountStatus();
        updateTotalPrice();
    }
}

void CustomerMainWindow::onReturnOrderClicked()
{
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param this The this parameter used by the function.
 */

    ReturnOrderDialog returnDialog(this);
    if (returnDialog.exec() == QDialog::Accepted)
    {
        loadInventory();
    }
}

void CustomerMainWindow::onLogoutClicked()
{
    if (QMessageBox::question(this, "Logout", "Are you sure you want to logout?") 
        == QMessageBox::Yes)
    {
        emit logoutRequested();
        this->close();
    }
}

void CustomerMainWindow::updatePlantDisplay()
{
    const QString selectedType = ui->plantTypeCombo->currentText();
    const QString selectedMaturity = ui->maturityCombo->currentText();

    QListWidgetItem *currentItem = ui->inventoryList->currentItem();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    bool currentItemVisible = (currentItem == nullptr);
    int visibleCount = 0;

    for (int i = 0; i < ui->inventoryList->count(); ++i)
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param i The i parameter used by the function.
 */

        QListWidgetItem *item = ui->inventoryList->item(i);
        const QString text = item->text();

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param Qt::CaseInsensitive TODO - describe parameter
 */

        const bool matchesType = (selectedType == "All") || text.contains(selectedType, Qt::CaseInsensitive);


        const bool matchesMaturity = (selectedMaturity == "All") || text.contains(selectedMaturity, Qt::CaseInsensitive);
        const bool isVisible = matchesType && matchesMaturity;

/**
 * @brief Execute the function's primary operation.
 * @param !isVisible TODO - describe parameter
 */

        item->setHidden(!isVisible);

        if (isVisible)
        {
            ++visibleCount;
        }
        else if (item == currentItem)
        {
            currentItemVisible = false;
        }
    }

    if (!currentItemVisible)
    {
        ui->inventoryList->clearSelection();
        selectedPlant = nullptr;
/**
 * @brief Execute the function's primary operation.
 * @param details" TODO - describe parameter
 */

        ui->plantDetailsText->setPlainText("Select a plant to view details");
    }

/**
 * @brief Execute the function's primary operation.
 * @param %1").arg(visibleCount) TODO - describe parameter
 */

    ui->plantCountLabel->setText(QString("Available Plants: %1").arg(visibleCount));
}

void CustomerMainWindow::updateCartDisplay()
{
    ui->cartList->clear();
    
    if (!facade)
    {
        updateTotalPrice();
        updateDiscountStatus();
        return;
    }

    const std::vector<CustomerFacade::CartEntry> entries = facade->getCartEntries();
    int index = 1;

    for (const auto& entry : entries)
    {
        if (!entry.plant)
        {
            continue;
        }

        QStringList lines;
        lines << QString("%1. %2 (Plant) - R%3")
                    .arg(index++)
                    .arg(QString::fromStdString(entry.plant->getName()))
/**
 * @brief Execute the function's primary operation.
 * @param entry.plant->getPrice() TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

                    .arg(entry.plant->getPrice(), 0, 'f', 2);

        for (auto decoration : entry.decorations)
        {
            lines << QString("   + %1 (Decoration) - R%2")
                        .arg(QString::fromStdString(CustomerFacade::decorationName(decoration)))
/**
 * @brief Execute the function's primary operation.
 * @param CustomerFacade::decorationPrice(decoration) TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

                        .arg(CustomerFacade::decorationPrice(decoration), 0, 'f', 2);
        }

        if (!entry.decorations.empty())
        {
            lines << QString("   = Item Total: R%1")
/**
 * @brief Execute the function's primary operation.
 * @param facade->getEntryTotal(entry) TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

                        .arg(facade->getEntryTotal(entry), 0, 'f', 2);
        }

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param lines.join('\n') TODO - describe parameter
 */

        QListWidgetItem* item = new QListWidgetItem(lines.join('\n'));
/**
 * @brief Execute the function's primary operation.
 * @param Qt::UserRole TODO - describe parameter
 * @param QVariant::fromValue(static_cast<void*>(entry.plant)) TODO - describe parameter
 */

        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<void*>(entry.plant)));


        ui->cartList->addItem(item);
    }

    updateTotalPrice();
    updateDiscountStatus();
}

void CustomerMainWindow::updateTotalPrice()
{
    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param R0.00" TODO - describe parameter
 */

        ui->totalPriceLabel->setText("Total: R0.00");
        return;
    }

    const double total = facade->getOrderTotal();
    const double subtotal = facade->getSubtotal();
    const double savings = subtotal - total;

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param R%1").arg(total TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

    QString label = QString("Total: R%1").arg(total, 0, 'f', 2);
    if (savings > 0.0)
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param R%1)").arg(savings TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

        label += QString(" (Saved R%1)").arg(savings, 0, 'f', 2);
    }

/**
 * @brief Execute the function's primary operation.
 * @param label The label parameter used by the function.
 */

    ui->totalPriceLabel->setText(label);
}

Plant* CustomerMainWindow::getSelectedPlant()
{
    return selectedPlant;
}

std::vector<CustomerFacade::DecorationType> CustomerMainWindow::gatherSelectedDecorations() const
{
    std::vector<CustomerFacade::DecorationType> decorations;

    if (ui->redPotCheck->isChecked())
    {
/**
 * @brief Execute the function's primary operation.
 * @param CustomerFacade::DecorationType::RedPot TODO - describe parameter
 */

        decorations.push_back(CustomerFacade::DecorationType::RedPot);
    }
    if (ui->ribbonCheck->isChecked())
    {
/**
 * @brief Execute the function's primary operation.
 * @param CustomerFacade::DecorationType::Ribbon TODO - describe parameter
 */

        decorations.push_back(CustomerFacade::DecorationType::Ribbon);
    }
    if (ui->scentCheck->isChecked())
    {
/**
 * @brief Execute the function's primary operation.
 * @param CustomerFacade::DecorationType::Scent TODO - describe parameter
 */

        decorations.push_back(CustomerFacade::DecorationType::Scent);
    }
    if (ui->giftWrapCheck->isChecked())
    {
/**
 * @brief Execute the function's primary operation.
 * @param CustomerFacade::DecorationType::GiftWrap TODO - describe parameter
 */

        decorations.push_back(CustomerFacade::DecorationType::GiftWrap);
    }

    return decorations;
}

void CustomerMainWindow::clearDecorationCheckboxes()
{


    ui->redPotCheck->setChecked(false);


    ui->ribbonCheck->setChecked(false);


    ui->scentCheck->setChecked(false);


    ui->giftWrapCheck->setChecked(false);
}

void CustomerMainWindow::updateDiscountStatus()
{
    if (!facade)
    {
/**
 * @brief Execute the function's primary operation.
 * @param discount" TODO - describe parameter
 */

        ui->discountStatusLabel->setText("No discount");
/**
 * @brief Execute the function's primary operation.
 * @param gray;" TODO - describe parameter
 */

        ui->discountStatusLabel->setStyleSheet("color: gray;");
        return;
    }

    const double rate = facade->getDiscountRate();
    const double subtotal = facade->getSubtotal();
    const double total = facade->getOrderTotal();
    const double savings = subtotal - total;

    if (rate > 0.0)
    {
        QString source;
        if (facade->hasManualDiscount())
        {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param facade->getDiscountCode() TODO - describe parameter
 */

            const QString code = QString::fromStdString(facade->getDiscountCode());
            source = code.isEmpty() ? QStringLiteral("manual discount")
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param %1").arg(code TODO - describe parameter
 */

                                    : QStringLiteral("code %1").arg(code);
        }
        else
        {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param items)" TODO - describe parameter
 */

            source = QStringLiteral("automatic (10+ items)");
        }

        QString label = QStringLiteral("Discount applied (%1% off via %2)")
                             .arg(rate * 100.0, 0, 'f', 0)
/**
 * @brief Execute the function's primary operation.
 * @param source The source parameter used by the function.
 */

                             .arg(source);
        if (savings > 0.0)
        {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param R%1").arg(savings TODO - describe parameter
 * @param 0 The 0 parameter used by the function.
 * @param 'f' TODO - describe parameter
 * @param 2 The 2 parameter used by the function.
 */

            label += QStringLiteral(" — Saved R%1").arg(savings, 0, 'f', 2);
        }


        ui->discountStatusLabel->setText(label);
/**
 * @brief Execute the function's primary operation.
 * @param green;" TODO - describe parameter
 */

        ui->discountStatusLabel->setStyleSheet("color: green;");
    }
    else
    {


        ui->discountStatusLabel->setText("No discount");


        ui->discountStatusLabel->setStyleSheet("color: gray;");
    }
}

