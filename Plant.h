#ifndef PLANT_H
#define PLANT_H

#include "PlantComponent.h"
#include "PlantGrowthState.h"

#include "Water.h"
#include "HydratedState.h"
#include "NotHydratedState.h"

#include "Fertilizer.h"
#include "FertilizedState.h"
#include "NonFertilizerState.h"

#include "PlantGrowthState.h"
#include "PlantMonitor.h"

#include <string>

class WaterMonitor;
class FertilizerMonitor;
class DeadMonitor;

class Plant : public PlantComponent
{
	protected:
		std::string type; //Child
		double price; //Child
		int careCount; //Plant
		int health; //Plant

		Water* waterState;//Needs Retention
		int waterLevel;//Plant
		double waterRetention;//Child //How slowly water level decreases
		int lowWaterLevel;//Child

		Fertilizer* fertilizerState;//Needs Retention
		int fertilizerLevel;//Plant
		double fertilizerRetention;//Child// How slowly fertilizer level decreases
		int lowFertilizerLevel;//Child

		int plantId;                    // Instance ID for each plant
    	static int nextPlantId;         // Static variable to track next ID

		PlantGrowthState* growthState;

		//Monitoring
		WaterMonitor* waterMonitor;
		FertilizerMonitor* fertilizerMonitor;
		DeadMonitor* deadMonitor;

		friend class PlantSnapshot;

	public:
		Plant();
		virtual ~Plant();
		void hoursHasPassed();
		// Plant(PlantGrowthState *state, int waterLevel, int fertilizerLevel);
		void waterPlant();//Water plant to full and set state
		void fertilizePlant();// Fertilize plant to full and set state
		void print();//Does this print plant name / plant info?

		std::string getWaterStateName();
		std::string getFertilizerStateName();
		std::string getMaturityStateName();
		int getHealth();

		void attachWaterMonitor(WaterMonitor* observer);
		void attachFertilizerMonitor(FertilizerMonitor* observer);
		void attachDeadMonitor(DeadMonitor* observer);

		double getPrice();
		virtual std::string getName() = 0;
		PlantGrowthState* getState();
		int getWaterLevel();
		int getFertilizerLevel();
		int getPlantId();

	protected:
		//Only if at 100 health should the plant grow (careCount increase)
		int getCareCount();//Return care count
		int getCareCountEffect();//Return care count effect based on water and fertilizer states
		void increaseCareCount();//Increase care count by amount
		void setGrowthState(PlantGrowthState* state);//Set growth state
		void checkGrowthLevel();//Check and update growth state based on care count
	

		int getHealthEffects();
		void healthEffects();//Calculate new health // Can put plant in deadState

		void setWaterState(Water* waterState);
		void setFertilizerState(Fertilizer* fertilizerState);
		void checkWaterLevel(); // changes water state based on the current water level // Notify observers here when NotHydratedState is set
		void checkFertilizerLevel();// changes fertilizer state based on the current fertilizer level // Notify observers here when NotFertilizerState is set
		void decreaseWaterLevel();
		void decreaseFertilizerLevel();
		void internalsTimeElapse();// updates health, water level, and fertilizer level over time

		//Only if at 100 health should the plant grow (careCount increase)

};

#endif