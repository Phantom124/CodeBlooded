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

#include <string>

class Plant : public PlantComponent
{
	protected:
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
		
	public:
		Plant();
		virtual ~Plant();
		void hoursHasPassed();
		// Plant(PlantGrowthState *state, int waterLevel, int fertilizerLevel);
		void waterPlant();//Water plant to full and set state
		void fertilizePlant();// Fertilize plant to full and set state
		// void add(Plant *extra);//WHY IS THIS HERE???
		void print();//Does this print plant name / plant info?
		virtual std::string getName();
		double getPrice();
		// virtual std::string getName() = 0;
	protected:
		int getHealthEffects();
		void healthEffects();
		void setWaterState(Water* waterState);
		void setFertilizerState(Fertilizer* fertilizerState);
		void checkWaterLevel(); // changes water state based on the current water level // Notify observers here when NotHydratedState is set
		void checkFertilizerLevel();// changes fertilizer state based on the current fertilizer level // Notify observers here when NotFertilizerState is set
		void decreaseWaterLevel();
		void decreaseFertilizerLevel();
		void internalsTimeElapse();// updates health, water level, and fertilizer level over time

		//Growth functions go here
		//Only if at 100 health should the plant grow (careCount increase)



		//Add Observer here
};

#endif
