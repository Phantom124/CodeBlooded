#ifndef STAFFMAINWINDOW_H
#define STAFFMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class StaffMainWindow;
}

class StaffMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StaffMainWindow(QWidget *parent = nullptr);
    ~StaffMainWindow();

signals:
    void logoutRequested();

private slots:
    void onLogoutClicked();
    void onPlantManagementClicked();
    void onStaffManagementClicked();

private:
    Ui::StaffMainWindow *ui;
    
    void setupConnections();
};

#endif
