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
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    // Load custom font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/resources/font/PressStart2P.ttf");
    if (fontId != -1)
    {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        if (!fontFamilies.isEmpty())
        {
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
    g_customerFacade = new CustomerFacade(g_sharedInventory, g_sharedCaretaker);
    g_greenHouseFacade = new GreenHouseFacade(g_sharedInventory, g_sharedStaffSystem);

    QFile styleFile(":/styles/styles.qss"); // Load stylesheet
    if (styleFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream stream(&styleFile);
        QString styleSheet = stream.readAll();
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
    loginDialog.show();
    
    int result = app.exec();
    
    // Cleanup shared instances
    delete g_greenHouseFacade;
    delete g_customerFacade;
    delete g_sharedStaffSystem;
    delete g_sharedCaretaker;
    delete g_sharedInventory;
    
    return result;
}
