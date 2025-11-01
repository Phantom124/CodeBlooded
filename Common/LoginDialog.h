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
    bool validateCredentials(const QString &username, const QString &password);
};

#endif // LOGINDIALOG_H
