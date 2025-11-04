/**
 * @file Common/LoginDialog.cpp
 * @brief LoginDialog.cpp — Header and declarations for the LoginDialog.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include "../CustomerWindows/CustomerMainWindow.h"
#include "../StaffWindows/StaffMainWindow.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , userType(Customer)
{
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 */

    ui->setupUi(this);
    setupConnections();
    
    // Set window properties
/**
 * @brief Execute the function's primary operation.
 * @param Login" TODO - describe parameter
 */

    setWindowTitle("Plant Nursery - Login");
/**
 * @brief Execute the function's primary operation.
 * @param true The true parameter used by the function.
 */

    setModal(true);
    
    // Default selection - Customer mode (credentials hidden)


    ui->customerRadio->setChecked(true);
/**
 * @brief Execute the function's primary operation.
 * @param false The false parameter used by the function.
 */

    ui->credentialsGroup->setVisible(false);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setupConnections()
{
/**
 * @brief Execute the function's primary operation.
 * @param ui->customerRadio TODO - describe parameter
 * @param &QRadioButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onCustomerButtonClicked TODO - describe parameter
 */

    connect(ui->customerRadio, &QRadioButton::clicked, this, &LoginDialog::onCustomerButtonClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->staffRadio TODO - describe parameter
 * @param &QRadioButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onStaffButtonClicked TODO - describe parameter
 */

    connect(ui->staffRadio, &QRadioButton::clicked, this, &LoginDialog::onStaffButtonClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->loginButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onLoginButtonClicked TODO - describe parameter
 */

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginButtonClicked);
/**
 * @brief Execute the function's primary operation.
 * @param ui->exitButton TODO - describe parameter
 * @param &QPushButton::clicked TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &QDialog::reject TODO - describe parameter
 */

    connect(ui->exitButton, &QPushButton::clicked, this, &QDialog::reject);
}

void LoginDialog::onCustomerButtonClicked()
{
    userType = Customer;


    ui->credentialsGroup->setVisible(false);
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();


    ui->usernameEdit->setEnabled(false);


    ui->passwordEdit->setEnabled(false);
}

void LoginDialog::onStaffButtonClicked()
{
    userType = Staff;


    ui->credentialsGroup->setVisible(true);


    ui->usernameEdit->setEnabled(true);


    ui->passwordEdit->setEnabled(true);
}

void LoginDialog::onLoginButtonClicked()
{
    if (userType == Staff)
    {
        QString username = ui->usernameEdit->text();
        QString password = ui->passwordEdit->text();
        
        if (username.isEmpty() || password.isEmpty())
        {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Error" TODO - describe parameter
 * @param password." TODO - describe parameter
 */

            QMessageBox::warning(this, "Login Error", "Please enter username and password.");
            return;
        }
        
        if (!validateCredentials(username, password))
        {
/**
 * @brief Execute the function's primary operation.
 * @param this The this parameter used by the function.
 * @param Failed" TODO - describe parameter
 * @param password." TODO - describe parameter
 */

            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
            return;
        }
    }
    
    // Hide login dialog and open appropriate window
    this->hide();
    
    if (userType == Customer)
    {
        CustomerMainWindow *customerWindow = new CustomerMainWindow();
/**
 * @brief Execute the function's primary operation.
 * @param Qt::WA_DeleteOnClose TODO - describe parameter
 */

        customerWindow->setAttribute(Qt::WA_DeleteOnClose);
/**
 * @brief Execute the function's primary operation.
 * @param customerWindow The customerWindow parameter used by the function.
 * @param &CustomerMainWindow::logoutRequested TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onChildLogoutRequested TODO - describe parameter
 */

        connect(customerWindow, &CustomerMainWindow::logoutRequested, this, &LoginDialog::onChildLogoutRequested);
/**
 * @brief Execute the function's primary operation.
 * @param customerWindow The customerWindow parameter used by the function.
 * @param &CustomerMainWindow::destroyed TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onChildWindowClosed TODO - describe parameter
 */

        connect(customerWindow, &CustomerMainWindow::destroyed, this, &LoginDialog::onChildWindowClosed);
        customerWindow->show();
    }
    else
    {
        StaffMainWindow *staffWindow = new StaffMainWindow();


        staffWindow->setAttribute(Qt::WA_DeleteOnClose);
/**
 * @brief Execute the function's primary operation.
 * @param staffWindow The staffWindow parameter used by the function.
 * @param &StaffMainWindow::logoutRequested TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onChildLogoutRequested TODO - describe parameter
 */

        connect(staffWindow, &StaffMainWindow::logoutRequested, this, &LoginDialog::onChildLogoutRequested);
/**
 * @brief Execute the function's primary operation.
 * @param staffWindow The staffWindow parameter used by the function.
 * @param &StaffMainWindow::destroyed TODO - describe parameter
 * @param this The this parameter used by the function.
 * @param &LoginDialog::onChildWindowClosed TODO - describe parameter
 */

        connect(staffWindow, &StaffMainWindow::destroyed, this, &LoginDialog::onChildWindowClosed);
        staffWindow->show();
    }
}

void LoginDialog::onChildWindowClosed()
{
    // Reset dialog and show it again
    resetDialog();
    this->show();
}

void LoginDialog::onChildLogoutRequested()
{
    resetDialog();
    if (!this->isVisible())
    {
        this->show();
    }
}

bool LoginDialog::validateCredentials(const QString &username, const QString &password)
{
    //Simple validation for now only checks admin/admin as details
    return (username == "admin" && password == "admin");
}

void LoginDialog::resetDialog()
{
    // Reset to customer mode


    ui->customerRadio->setChecked(true);


    ui->credentialsGroup->setVisible(false);
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();


    ui->usernameEdit->setEnabled(false);


    ui->passwordEdit->setEnabled(false);
    userType = Customer;
}
