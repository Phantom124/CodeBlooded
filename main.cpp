/**
 * @file main.cpp
 * @brief main.cpp — Header and declarations for the main.cpp component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDatabase>
#include "Common/LoginDialog.h"
#include "ProxyGreenHouseInventory.h"
#include "RealGreenHouseInventory.h"
#include "Caretaker.h"
#include "StaffSystem.h"
#include "CustomerFacade.h"
#include "GreenHouseFacade.h"

// Global shared instances - accessible across all windows
ProxyGreenHouseInventory* g_sharedInventory = nullptr;
Caretaker* g_sharedCaretaker = nullptr;
StaffSystem* g_sharedStaffSystem = nullptr;
CustomerFacade* g_customerFacade = nullptr;
GreenHouseFacade* g_greenHouseFacade = nullptr;

int main(int argc, char *argv[])
{
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param argc The argc parameter used by the function.
 * @param argv The argv parameter used by the function.
 */

    QApplication app(argc, argv);
/**
 * @brief Execute the function's primary operation.
 * @param false The false parameter used by the function.
 */

    app.setQuitOnLastWindowClosed(false);

    // Load custom font
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param ":/fonts/resources/font/PressStart2P.ttf" TODO - describe parameter
 */

    int fontId = QFontDatabase::addApplicationFont(":/fonts/resources/font/PressStart2P.ttf");
    if (fontId != -1)
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param fontId The fontId parameter used by the function.
 */

        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        if (!fontFamilies.isEmpty())
        {
/**
 * @brief Execute the function's primary operation.
 * @param QFont(fontFamilies.at(0) TODO - describe parameter
 * @param 10) TODO - describe parameter
 */

            app.setFont(QFont(fontFamilies.at(0), 10));
        }
    }
    else
    {
        QMessageBox::warning(nullptr, "Font Error", 
            "Could not load Press Start 2P font. Application will use default font.");
    }

    // Initialize shared backend systems
    g_sharedInventory = new ProxyGreenHouseInventory();
    g_sharedCaretaker = new Caretaker();
    g_sharedStaffSystem = new StaffSystem();
    
    // Initialize facades with shared instances
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param g_sharedInventory The g_sharedInventory parameter used by the function.
 * @param g_sharedCaretaker The g_sharedCaretaker parameter used by the function.
 */

    g_customerFacade = new CustomerFacade(g_sharedInventory, g_sharedCaretaker);
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param g_sharedInventory The g_sharedInventory parameter used by the function.
 * @param g_sharedStaffSystem The g_sharedStaffSystem parameter used by the function.
 */

    g_greenHouseFacade = new GreenHouseFacade(g_sharedInventory, g_sharedStaffSystem);

/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param ":/styles/styles.qss" TODO - describe parameter
 */

    QFile styleFile(":/styles/styles.qss"); // Load stylesheet
    if (styleFile.open(QFile::ReadOnly | QFile::Text))
    {
/**
 * @brief Execute the function's primary operation.
 * @return The return value of the function; see implementation for details.
 * @param &styleFile TODO - describe parameter
 */

        QTextStream stream(&styleFile);
        QString styleSheet = stream.readAll();
/**
 * @brief Execute the function's primary operation.
 * @param styleSheet The styleSheet parameter used by the function.
 */

        app.setStyleSheet(styleSheet);
        styleFile.close();
    }
    else
    {
        QMessageBox::warning(nullptr, "Style Error", 
            "Could not load stylesheet. Application will use default styling.");
    }

    // Show login dialog
    LoginDialog loginDialog;
/**
 * @brief Execute the function's primary operation.
 * @param &loginDialog TODO - describe parameter
 * @param &QDialog::rejected TODO - describe parameter
 * @param &app TODO - describe parameter
 * @param &QApplication::quit TODO - describe parameter
 */

    QObject::connect(&loginDialog, &QDialog::rejected, &app, &QApplication::quit);
    loginDialog.show();
    
    int result = app.exec();

    if (fontId != -1)
    {
/**
 * @brief Execute the function's primary operation.
 * @param fontId The fontId parameter used by the function.
 */

        QFontDatabase::removeApplicationFont(fontId);
    }
    
    // Cleanup shared instances
    delete g_greenHouseFacade;
    delete g_customerFacade;
    delete g_sharedStaffSystem;
    delete g_sharedCaretaker;
    delete g_sharedInventory;
    
    return result;
}
