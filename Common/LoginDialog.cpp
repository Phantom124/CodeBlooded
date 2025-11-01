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
    ui->setupUi(this);
    setupConnections();
    
    // Set window properties
    setWindowTitle("Plant Nursery - Login");
    setModal(true);
    
    // Default selection - Customer mode (credentials hidden)
    ui->customerRadio->setChecked(true);
    ui->credentialsGroup->setVisible(false);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setupConnections()
{
    connect(ui->customerRadio, &QRadioButton::clicked, this, &LoginDialog::onCustomerButtonClicked);
    connect(ui->staffRadio, &QRadioButton::clicked, this, &LoginDialog::onStaffButtonClicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginButtonClicked);
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
            QMessageBox::warning(this, "Login Error", "Please enter username and password.");
            return;
        }
        
        if (!validateCredentials(username, password))
        {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
            return;
        }
    }
    
    // Hide login dialog and open appropriate window
    this->hide();
    
    if (userType == Customer)
    {
        CustomerMainWindow *customerWindow = new CustomerMainWindow();
        customerWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(customerWindow, &CustomerMainWindow::logoutRequested, this, &LoginDialog::onChildLogoutRequested);
        connect(customerWindow, &CustomerMainWindow::destroyed, this, &LoginDialog::onChildWindowClosed);
        customerWindow->show();
    }
    else
    {
        StaffMainWindow *staffWindow = new StaffMainWindow();
        staffWindow->setAttribute(Qt::WA_DeleteOnClose);
        connect(staffWindow, &StaffMainWindow::logoutRequested, this, &LoginDialog::onChildLogoutRequested);
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
