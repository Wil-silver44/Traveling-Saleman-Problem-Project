#ifndef SIMULATIONRUNNER_HPP
#define SIMULATIONRUNNER_HPP
#include<iostream>
#include "BruteForceSim.hpp"

//header comment goes here

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
		double geneticOptPath;
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
