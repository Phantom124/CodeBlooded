/**
 * @file Common/SharedInstances.h
 * @brief SharedInstances.h — Header and declarations for the SharedInstances.h component.
 * @author Team: Jared Williams, Zaman Bassa, Obed Edom Mbaya, Ange Yehouessi, Joshua Mahabeer
 * @date 2025-11-04
 */

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
