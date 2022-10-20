#ifndef SIMULATIONRUNNER_HPP
#define SIMULATIONRUNNER_HPP
#include<iostream>

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
	public:
		SimulationRunner();
		int GetNumCities();
		void RunBruteForce();
		void RunGenetic();
		void PrintResult();
};

#endif
