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
    ui->setupUi(this);
    setupConnections();
    loadInventory();
    updateCartDisplay();
    
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
    connect(ui->refreshButton, &QPushButton::clicked, this, &CustomerMainWindow::onRefreshInventoryClicked);
    
    // Plant selection
    connect(ui->inventoryList, &QListWidget::itemClicked, this, &CustomerMainWindow::onPlantSelected);
    connect(ui->addToCartButton, &QPushButton::clicked, this, &CustomerMainWindow::onAddToCartClicked);
    connect(ui->removeFromCartButton, &QPushButton::clicked, this, &CustomerMainWindow::onRemoveFromCartClicked);
    
    // Decorations
    connect(ui->redPotCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
    connect(ui->ribbonCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
    connect(ui->scentCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
    connect(ui->giftWrapCheck, &QCheckBox::stateChanged, this, &CustomerMainWindow::onDecorationCheckChanged);
    
    // Discount
    connect(ui->applyDiscountButton, &QPushButton::clicked, this, &CustomerMainWindow::onApplyDiscountClicked);
    connect(ui->discountCodeEdit, &QLineEdit::textChanged, this, &CustomerMainWindow::onDiscountCodeChanged);
    
    // Order management
    connect(ui->checkoutButton, &QPushButton::clicked, this, &CustomerMainWindow::onCheckoutClicked);
    connect(ui->clearCartButton, &QPushButton::clicked, this, &CustomerMainWindow::onClearCartClicked);
    connect(ui->returnOrderButton, &QPushButton::clicked, this, &CustomerMainWindow::onReturnOrderClicked);
    
    // Window management
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
            .arg(plant->getPrice(), 0, 'f', 2);
        
        QListWidgetItem *item = new QListWidgetItem(itemText);
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<void*>(plant)));
        ui->inventoryList->addItem(item);
    }
    
    updatePlantDisplay();
}

void CustomerMainWindow::onFilterChanged(int index)
{
    Q_UNUSED(index);
    updatePlantDisplay();
}

void CustomerMainWindow::onRefreshInventoryClicked()
{
    loadInventory();
    QMessageBox::information(this, "Refresh", "Inventory refreshed successfully!");
}

void CustomerMainWindow::onPlantSelected(QListWidgetItem *item)
{
    if (!item) return;
    
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
     .arg(QString::fromStdString(plant->getFertilizerStateName()));
    
    ui->plantDetailsText->setPlainText(details);
}

void CustomerMainWindow::onAddToCartClicked()
{
    Plant *plant = getSelectedPlant();
    if (!plant)
    {
        QMessageBox::warning(this, "No Selection", "Please select a plant from inventory.");
        return;
    }
    
    if (!facade) return;
    
    const auto decorations = gatherSelectedDecorations();
    facade->addPlantToOrder(plant, decorations);
    
    loadInventory();
    updateCartDisplay();
    updateDiscountStatus();
    clearDecorationCheckboxes();
    
    QMessageBox::information(this, "Success", "Plant added to cart!");
}

void CustomerMainWindow::onRemoveFromCartClicked()
{
    int currentRow = ui->cartList->currentRow();
    if (currentRow < 0)
    {
        QMessageBox::warning(this, "No Selection", "Please select an item to remove from cart.");
        return;
    }
    
    if (!facade) return;
    
    QListWidgetItem* item = ui->cartList->item(currentRow);
    if (!item)
    {
        return;
    }

    Plant* plant = static_cast<Plant*>(item->data(Qt::UserRole).value<void*>());
    if (plant)
    {
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
        facade->applyDiscount(true, code.toStdString());
        updateTotalPrice();
        updateDiscountStatus();
        QMessageBox::information(this, "Discount Applied", "10% discount has been applied to your order!");
    }
    else if (code.isEmpty())
    {
        facade->applyDiscount(false);
        updateTotalPrice();
        updateDiscountStatus();
    }
    else
    {
        facade->applyDiscount(false);
        updateTotalPrice();
        ui->discountStatusLabel->setText("Invalid discount code (no discount applied)");
        ui->discountStatusLabel->setStyleSheet("color: #b71c1c;");
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
        QMessageBox::warning(this, "Empty Cart", "Your cart is empty. Add items before checkout.");
        return;
    }
    
    Receipt* receipt = facade->checkout();
    
    if (receipt)
    {
        QString receiptText = QString(
            "Receipt ID: %1\n\n%2"
        ).arg(QString::fromStdString(receipt->getReceiptID()))
         .arg(QString::fromStdString(receipt->getOrderInfo()));
        
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
    bool currentItemVisible = (currentItem == nullptr);
    int visibleCount = 0;

    for (int i = 0; i < ui->inventoryList->count(); ++i)
    {
        QListWidgetItem *item = ui->inventoryList->item(i);
        const QString text = item->text();

        const bool matchesType = (selectedType == "All") || text.contains(selectedType, Qt::CaseInsensitive);
        const bool matchesMaturity = (selectedMaturity == "All") || text.contains(selectedMaturity, Qt::CaseInsensitive);
        const bool isVisible = matchesType && matchesMaturity;

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
        ui->plantDetailsText->setPlainText("Select a plant to view details");
    }

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
                    .arg(entry.plant->getPrice(), 0, 'f', 2);

        for (auto decoration : entry.decorations)
        {
            lines << QString("   + %1 (Decoration) - R%2")
                        .arg(QString::fromStdString(CustomerFacade::decorationName(decoration)))
                        .arg(CustomerFacade::decorationPrice(decoration), 0, 'f', 2);
        }

        if (!entry.decorations.empty())
        {
            lines << QString("   = Item Total: R%1")
                        .arg(facade->getEntryTotal(entry), 0, 'f', 2);
        }

        QListWidgetItem* item = new QListWidgetItem(lines.join('\n'));
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
        ui->totalPriceLabel->setText("Total: R0.00");
        return;
    }

    const double total = facade->getOrderTotal();
    const double subtotal = facade->getSubtotal();
    const double savings = subtotal - total;

    QString label = QString("Total: R%1").arg(total, 0, 'f', 2);
    if (savings > 0.0)
    {
        label += QString(" (Saved R%1)").arg(savings, 0, 'f', 2);
    }

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
        decorations.push_back(CustomerFacade::DecorationType::RedPot);
    }
    if (ui->ribbonCheck->isChecked())
    {
        decorations.push_back(CustomerFacade::DecorationType::Ribbon);
    }
    if (ui->scentCheck->isChecked())
    {
        decorations.push_back(CustomerFacade::DecorationType::Scent);
    }
    if (ui->giftWrapCheck->isChecked())
    {
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
        ui->discountStatusLabel->setText("No discount");
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
            const QString code = QString::fromStdString(facade->getDiscountCode());
            source = code.isEmpty() ? QStringLiteral("manual discount")
                                    : QStringLiteral("code %1").arg(code);
        }
        else
        {
            source = QStringLiteral("automatic (10+ items)");
        }

        QString label = QStringLiteral("Discount applied (%1% off via %2)")
                             .arg(rate * 100.0, 0, 'f', 0)
                             .arg(source);
        if (savings > 0.0)
        {
            label += QStringLiteral(" — Saved R%1").arg(savings, 0, 'f', 2);
        }

        ui->discountStatusLabel->setText(label);
        ui->discountStatusLabel->setStyleSheet("color: green;");
    }
    else
    {
        ui->discountStatusLabel->setText("No discount");
        ui->discountStatusLabel->setStyleSheet("color: gray;");
    }
}

