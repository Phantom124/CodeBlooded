/**
 * @file Common/LoginDialog.h
 * @brief LoginDialog.h — Header and declarations for the LoginDialog.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    enum UserType {
        Customer,
        Staff
    };

    UserType getUserType() const { return userType; }
    
    void resetDialog();

private slots:
    void onCustomerButtonClicked();
    void onStaffButtonClicked();
    void onLoginButtonClicked();
    void onChildWindowClosed();
    void onChildLogoutRequested();

private:
    Ui::LoginDialog *ui;
    UserType userType;
    
    void setupConnections();
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param &username TODO - describe parameter
 * @param &password TODO - describe parameter
 */

    bool validateCredentials(const QString &username, const QString &password);
};

#endif // LOGINDIALOG_H
