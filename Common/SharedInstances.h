#ifndef SHAREDINSTANCES_H
#define SHAREDINSTANCES_H

// Forward declarations
class ProxyGreenHouseInventory;
class Caretaker;
class StaffSystem;
class CustomerFacade;
class GreenHouseFacade;

// External declarations for global shared instances
extern ProxyGreenHouseInventory* g_sharedInventory;
extern Caretaker* g_sharedCaretaker;
extern StaffSystem* g_sharedStaffSystem;
extern CustomerFacade* g_customerFacade;
extern GreenHouseFacade* g_greenHouseFacade;

#endif
