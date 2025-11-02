#include "StaffMainWindow.h"
#include "ui_StaffMainWindow.h"
#include "PlantManagementWidget.h"
#include "StaffManagementWidget.h"
#include <QMessageBox>

StaffMainWindow::StaffMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StaffMainWindow)
{
    ui->setupUi(this);
    setupConnections();
    
    setWindowTitle("Plant Nursery - Staff Portal");
    
    // Show plant management by default
    ui->stackedWidget->setCurrentIndex(0);
}

StaffMainWindow::~StaffMainWindow()
{
    delete ui;
}

void StaffMainWindow::setupConnections()
{
    connect(ui->logoutButton, &QPushButton::clicked, this, &StaffMainWindow::onLogoutClicked);
    connect(ui->plantManagementButton, &QPushButton::clicked, this, &StaffMainWindow::onPlantManagementClicked);
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
    ui->stackedWidget->setCurrentIndex(1);
}
