/**
 * @file StaffWindows/StaffMainWindow.h
 * @brief StaffMainWindow.h — Header and declarations for the StaffMainWindow.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 */

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
