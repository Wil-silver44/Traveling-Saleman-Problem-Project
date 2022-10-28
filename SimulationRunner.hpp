#ifndef SIMULATIONRUNNER_HPP
#define SIMULATIONRUNNER_HPP
#include <iostream>
#include "timer.hpp"
#include "BruteForceSim.hpp"
#include "GenAlgSim.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: SimulationRunner.hpp
 *   Assignment number: Project 3
 *
 *   Other comments regarding the file - defines methods and attributes fo taking in user input,
 *   running the two simulations.
 *
 ***************************************************************/

using std::cout;
using std::cin;
using std::endl;

class SimulationRunner
{
	private:
		int numCities;
		int numTours;
		int numGenerations;
		double percentMutation;
		double bruteForceOptPath;
		double bruteForceRunTime;
		double genAlgOptPath;
		double genAlgRunTime;
		Timer timeKeeper;
	public:
		SimulationRunner();
		void SetNumCities(int someNum);
		void SetNumTours(int someNum);
		void SetNumGenerations(int someNum);
		void SetPercentMutation(double somePercent);
		int GetNumCities();
		int GetNumTours();
		int GetNumGenerations();
		double GetPercentMutation();
		void RunBruteForce();
		void RunGenetic();
		void PrintResult();
};

#endif
