/**
 * @file StaffWindows/StaffMainWindow.cpp
 * @brief StaffMainWindow.cpp — Header and declarations for the StaffMainWindow.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "StaffMainWindow.h"
#include "ui_StaffMainWindow.h"
#include "PlantManagementWidget.h"
#include "StaffManagementWidget.h"
#include <QMessageBox>

StaffMainWindow::StaffMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StaffMainWindow)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);
    setupConnections();
    
/**
 * @brief Execute the function's primary operation.
 * @param Portal" TODO - describe parameter
 */

    setWindowTitle("Plant Nursery - Staff Portal");
    
    // Show plant management by default
/**
 * @brief Execute the function's primary operation.
 * @param 0 The 0 parameter used by the function.
 */

    ui->stackedWidget->setCurrentIndex(0);
}

StaffMainWindow::~StaffMainWindow()
{
    delete ui;
}

void StaffMainWindow::setupConnections()
{
/**
 * @brief Execute the function's primary operation.
 * @param ui->logoutButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffMainWindow::onLogoutClicked TODO - describe parameter
 */

    connect(ui->logoutButton, &QPushButton::clicked, this, &StaffMainWindow::onLogoutClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->plantManagementButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffMainWindow::onPlantManagementClicked TODO - describe parameter
 */

    connect(ui->plantManagementButton, &QPushButton::clicked, this, &StaffMainWindow::onPlantManagementClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->staffManagementButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &StaffMainWindow::onStaffManagementClicked TODO - describe parameter
 */

    connect(ui->staffManagementButton, &QPushButton::clicked, this, &StaffMainWindow::onStaffManagementClicked);
}

void StaffMainWindow::onLogoutClicked()
{
    if (QMessageBox::question(this, "Logout", "Are you sure you want to logout?") 
        == QMessageBox::Yes)
    {
        emit logoutRequested();
        this->close();
    }
}

void StaffMainWindow::onPlantManagementClicked()
{


    ui->stackedWidget->setCurrentIndex(0);
}

void StaffMainWindow::onStaffManagementClicked()
{
/**
 * @brief Execute the function's primary operation.
 * @param 1 The 1 parameter used by the function.
 */

    ui->stackedWidget->setCurrentIndex(1);
}
