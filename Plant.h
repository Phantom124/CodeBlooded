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
 * @brief Represents a plant in the simulation, with water, fertilizer, growth, and health tracking.
 *
 * This is an abstract base class for all specific plant types (e.g., Rose, Cactus, Sunflower).
 * It manages states like hydration, fertilization, growth stage, and health.
 * It also interacts with monitors (observers) for water, fertilizer, and death notifications.
 */
class Plant : public PlantComponent
{
protected:
	std::string type; /**< Type of the plant (e.g., Rose) */
	double price;	  /**< Base price of the plant */
	int careCount;	  /**< Number of care actions performed */
	int health;		  /**< Current health of the plant (0-100) */

	Water *waterState;	   /**< Current water state object */
	int waterLevel;		   /**< Current water level (0-100) */
	double waterRetention; /**< Rate at which water level decreases */
	int lowWaterLevel;	   /**< Threshold for low water notifications */

	Fertilizer *fertilizerState; /**< Current fertilizer state object */
	int fertilizerLevel;		 /**< Current fertilizer level (0-100) */
	double fertilizerRetention;	 /**< Rate at which fertilizer level decreases */
	int lowFertilizerLevel;		 /**< Threshold for low fertilizer notifications */

	int plantId;			/**< Unique ID for this plant instance */
	static int nextPlantId; /**< Static variable to generate unique IDs */

	PlantGrowthState *growthState; /**< Current growth state of the plant */

	// Monitoring
	WaterMonitor *waterMonitor;			  /**< Observer for water changes */
	FertilizerMonitor *fertilizerMonitor; /**< Observer for fertilizer changes */
	DeadMonitor *deadMonitor;			  /**< Observer for plant death */

	friend class PlantSnapshot; /**< Allows PlantSnapshot to access private members */
	PlantComponent *decorator;	/**< For Decorator pattern */

public:
	/**
	 * @brief Constructs a new Plant object.
	 * @param type The type of the plant.
	 * @param price Base price of the plant.
	 * @param waterRetention How fast the plant loses water.
	 * @param lowWaterLevel Threshold for low water notifications.
	 * @param fertilizerRetention How fast the plant loses fertilizer.
	 * @param lowFertilizerLevel Threshold for low fertilizer notifications.
	 */
	Plant(std::string type, double price, double waterRetention, int lowWaterLevel, double fertilizerRetention, int lowFertilizerLevel);

	/**
	 * @brief Destructor for Plant.
	 * Cleans up dynamically allocated state objects.
	 */
	virtual ~Plant();

	/**
	 * @brief Updates the plant state after an hour has passed.
	 */
	void hoursHasPassed();

	/**
	 * @brief Waters the plant to full and updates water state.
	 */
	void waterPlant();

	/**
	 * @brief Fertilizes the plant to full and updates fertilizer state.
	 */
	void fertilizePlant();

	/**
	 * @brief Prints current plant information including ID, water, fertilizer, health, growth state, and care count.
	 */
	void print();

	// State getters
	std::string getWaterStateName();
	std::string getFertilizerStateName();
	std::string getMaturityStateName();
	int getHealth();
	std::string getBaseName() const; // returns the base plant type without decorator suffixes

	// Observer attachment
	void attachWaterMonitor(WaterMonitor *observer);
	void attachFertilizerMonitor(FertilizerMonitor *observer);
	void attachDeadMonitor(DeadMonitor *observer);

	/**
	 * @brief Returns the price of the plant, factoring in growth stage effects.
	 * @return Price as double
	 */
	double getPrice();

	/**
	 * @brief Returns the name/type of the plant.
	 * @return Plant type as string
	 */
	std::string getName();

	PlantGrowthState *getState();
	int getWaterLevel();
	int getFertilizerLevel();
	int getPlantId();

	virtual void printPlant(); // oe add

	void add(PlantComponent *plantComponent); // zaman add

protected:
	// Internal methods for plant management
	int getCareCount();
	int getCareCountEffect();
	void increaseCareCount();
	void setGrowthState(PlantGrowthState *state);
	void checkGrowthLevel();

	int getHealthEffects();
	void healthEffects();

	void setWaterState(Water *waterState);
	void setFertilizerState(Fertilizer *fertilizerState);
	void checkWaterLevel();
	void checkFertilizerLevel();
	void decreaseWaterLevel();
	void decreaseFertilizerLevel();
	void internalsTimeElapse();
};

#endif
