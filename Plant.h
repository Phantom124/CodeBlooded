#ifndef PLANT_H
#define PLANT_H

#include "PlantComponent.h"
#include <string>

// forward declarations instead of including concrete state/monitor headers
class PlantGrowthState;
class Water;
class HydratedState;
class NotHydratedState;
class Fertilizer;
class FertilizedState;
class NonFertilizerState;

class WaterMonitor;
class FertilizerMonitor;
class DeadMonitor;

/**
 * @class Plant
 * @brief Abstract base for all plant types (Rose, Cactus, Sunflower, ...).
 *
 * The Plant class encapsulates common data and behaviour:
 * - water and fertilizer levels and their states
 * - growth state machine
 * - health tracking
 * - observer monitors for water/fertilizer/death
 *
 * Concrete plant types derive from this class and may extend behaviour.
 *
 * 
 * @author Zaman Bassa
 */
class Plant : public PlantComponent
{
protected:
	std::string type; /**< Type of the plant (e.g., Rose) */
	double price;     /**< Base price of the plant */
	int careCount;    /**< Number of care actions performed */
	int health;       /**< Current health (0-100) */

	Water *waterState;           /**< hydration state object */
	int waterLevel;              /**< hydration level 0-100 */
	double waterRetention;       /**< rate at which water decreases */
	int lowWaterLevel;           /**< threshold for low water notifications */

	Fertilizer *fertilizerState; /**< fertilizer state object */
	int fertilizerLevel;         /**< fertilizer level 0-100 */
	double fertilizerRetention;  /**< rate at which fertilizer decreases */
	int lowFertilizerLevel;      /**< threshold for fertilizer monitor notifications */

	int plantId;                 /**< unique id for the plant */
	static int nextPlantId;      /**< generator for unique ids */

	PlantGrowthState *growthState; /**< current growth state */

	// Monitors (observers)
	WaterMonitor *waterMonitor;
	FertilizerMonitor *fertilizerMonitor;
	DeadMonitor *deadMonitor;

	friend class PlantSnapshot;
	PlantComponent *decorator; /**< optional decorator component */

public:
	/**
	 * @brief Construct a Plant with configuration values.
	 * @param type Name/type of the plant (e.g., "Rose").
	 * @param price Base price for the plant.
	 * @param waterRetention Rate that water decays per time unit.
	 * @param lowWaterLevel Threshold at or below which water monitor notifies.
	 * @param fertilizerRetention Rate that fertilizer decays per time unit.
	 * @param lowFertilizerLevel Threshold for fertilizer monitor notifications.
	 */
/**
 * @brief Construct a new Plant with configuration values.
 * @param type The plant type/name (e.g., "Rose", "Cactus").
 * @param price The base price for the plant.
 * @param waterRetention Rate at which the plant's water level decays per time unit.
 * @param lowWaterLevel Water level threshold used to notify water monitors.
 * @param fertilizerRetention Rate at which the plant's fertilizer level decays per time unit.
 * @param lowFertilizerLevel Fertilizer level threshold used to notify fertilizer monitors.
 */
/**
 * @brief Execute the function's primary operation.
 * @param type The type parameter used by the function.
 * @param price The price parameter used by the function.
 * @param waterRetention The waterRetention parameter used by the function.
 * @param lowWaterLevel The lowWaterLevel parameter used by the function.
 * @param fertilizerRetention The fertilizerRetention parameter used by the function.
 * @param lowFertilizerLevel The lowFertilizerLevel parameter used by the function.
 */
	Plant(std::string type, double price, double waterRetention, int lowWaterLevel, double fertilizerRetention, int lowFertilizerLevel);

	/**
	 * @brief Virtual destructor cleans up dynamic state objects.
	 */
	virtual ~Plant();

	/**
	 * @brief Advance internal timers/state for an hour passing.
	 *
	 * This updates water/fertilizer levels, checks growth transitions,
	 * and notifies attached monitors when thresholds are crossed.
	 */
	void hoursHasPassed();

	/**
	 * @brief Water the plant to maximum and update hydration state.
	 */
	void waterPlant();

	/**
	 * @brief Fertilize the plant to maximum and update fertilizer state.
	 */
	void fertilizePlant();

	/**
	 * @brief Print a human-readable summary of this plant.
	 *
	 * Delegates to any decorator or prints base state (id, name, health, levels).
	 */
	void print();

	// State getters

	/**
	 * @brief Get a textual name for the water state.
	 * @return std::string Name of current water state (e.g., "Hydrated").
	 */
	std::string getWaterStateName();

	/**
	 * @brief Get a textual name for the fertilizer state.
	 * @return std::string Name of current fertilizer state.
	 */
	std::string getFertilizerStateName();

	/**
	 * @brief Get a textual name for the maturity / growth state.
	 * @return std::string Name of maturity state (e.g., "Mature").
	 */
	std::string getMaturityStateName();

	/**
	 * @brief Get current health value.
	 * @return int Health value (0-100).
	 */
	int getHealth();

	/**
	 * @brief Return the base plant type without decorator suffixes.
	 * @return std::string Base name of the plant.
	 */
	std::string getBaseName() const;

	// Observer attachment

	/**
	 * @brief Attach a WaterMonitor observer to this plant.
	 * @param observer Pointer to a WaterMonitor instance.
	 */
/**
 * @brief Attach a WaterMonitor observer to this plant.
 * @param observer Pointer to a WaterMonitor that will receive notifications when
 *        the plant's water level crosses configured thresholds.
 */
/**
 * @brief Execute the function's primary operation.
 * @param *observer TODO - describe parameter
 */
	void attachWaterMonitor(WaterMonitor *observer);

	/**
	 * @brief Attach a FertilizerMonitor observer to this plant.
	 * @param observer Pointer to a FertilizerMonitor instance.
	 */
/**
 * @brief Attach a FertilizerMonitor observer to this plant.
 * @param observer Pointer to a FertilizerMonitor that will receive notifications when
 *        the plant's fertilizer level crosses configured thresholds.
 */

	void attachFertilizerMonitor(FertilizerMonitor *observer);

	/**
	 * @brief Attach a DeadMonitor observer to this plant.
	 * @param observer Pointer to a DeadMonitor instance.
	 */
/**
 * @brief Attach a DeadMonitor observer to this plant.
 * @param observer Pointer to a DeadMonitor that will be notified when the plant
 *        transitions to a dead state.
 */

	void attachDeadMonitor(DeadMonitor *observer);

	/**
	 * @brief Compute current price for the plant factoring growth stage.
	 * @return double Adjusted price.
	 */
	double getPrice();

	/**
	 * @brief Get the display name / type of the plant.
	 * @return std::string Plant name/type.
	 */
	std::string getName();

	/**
	 * @brief Access the current growth state object.
	 * @return PlantGrowthState* Pointer to the growth state.
	 */
	PlantGrowthState *getState();

	/**
	 * @brief Get current water level.
	 * @return int Water level (0-100).
	 */
	int getWaterLevel();

	/**
	 * @brief Get current fertilizer level.
	 * @return int Fertilizer level (0-100).
	 */
	int getFertilizerLevel();

	/**
	 * @brief Get the unique plant id.
	 * @return int Plant id.
	 */
	int getPlantId();

	/**
	 * @brief Print plant using the class-specific print routine.
	 *
	 * This method exists so inventory can call p->printPlant() uniformly.
	 */
	virtual void printPlant();

	/**
	 * @brief Add a child PlantComponent (composite support).
	 * @param plantComponent Pointer to component to add.
	 */
/**
 * @brief Add a PlantComponent child to this composite.
 * @param plantComponent Pointer to the PlantComponent (Plant or PlantGroup) to add as a child.
 */
/**
 * @brief Execute the function's primary operation.
 * @param *plantComponent TODO - describe parameter
 */
	void add(PlantComponent *plantComponent);

protected:
	/** @brief Internal: number of cares performed. */
	int getCareCount();

	/** @brief Internal: effect factor from care count. */
	int getCareCountEffect();

	/** @brief Internal: increment care counter. */
	void increaseCareCount();

	/** @brief Internal: change current growth state. */
/**
 * @brief Set the plant's current growth state.
 * @param state Pointer to the new PlantGrowthState to assign to this plant.
 */
/**
 * @brief Execute the function's primary operation.
 * @param *state TODO - describe parameter
 */
	void setGrowthState(PlantGrowthState *state);

	/** @brief Internal: evaluate whether growth level should transition. */
	void checkGrowthLevel();

	/** @brief Internal: compute health effects. */
	int getHealthEffects();

	/** @brief Internal: apply health effects to internal fields. */
	void healthEffects();

	/** @brief Internal: set water state pointer. */
/**
 * @brief Replace the plant's current water state object.
 * @param waterState Pointer to the Water state object representing the new hydration behaviour.
 */
/**
 * @brief Execute the function's primary operation.
 * @param *waterState TODO - describe parameter
 */
	void setWaterState(Water *waterState);

	/** @brief Internal: set fertilizer state pointer. */
/**
 * @brief Replace the plant's current fertilizer state object.
 * @param fertilizerState Pointer to the Fertilizer state object representing the new fertilization behaviour.
 */
/**
 * @brief Execute the function's primary operation.
 * @param *fertilizerState TODO - describe parameter
 */
	void setFertilizerState(Fertilizer *fertilizerState);

	/** @brief Internal: check and notify water thresholds. */
	void checkWaterLevel();

	/** @brief Internal: check and notify fertilizer thresholds. */
	void checkFertilizerLevel();

	/** @brief Internal: decrease water level according to retention. */
	void decreaseWaterLevel();

	/** @brief Internal: decrease fertilizer level according to retention. */
	void decreaseFertilizerLevel();

	/** @brief Internal: perform per-hour internal changes. */
	void internalsTimeElapse();
};

#endif
