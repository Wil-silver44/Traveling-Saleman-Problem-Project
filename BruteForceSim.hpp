#ifndef BRUTEFORCESIM_HPP
#define BRUTEFORCESIM_HPP
#include <algorithm>
#include "CityGraph.hpp"

//Header comment goes here

using std::next_permutation;

class BruteForceSim
{
	private:
	int numCities;
	int numTours;
	CityGraph simGraph;
	double optPath;
	void CalcOptPath();
	public:
	BruteForceSim(int numCities, int numTours);
	void RunSim();
	double GetOptPath();
};

#endif
