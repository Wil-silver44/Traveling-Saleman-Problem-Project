#ifndef BRUTEFORCESIM_HPP
#define BRUTEFORCESIM_HPP
#include <algorithm>
#include "CityGraph.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: BruteForceSim.hpp
 *   Assignment number: Project 3
 *
 *   Other comments regarding the file - defines the attributes and methods
 *   for running a brute force simulation of the traveling salesman problem
 *
 ***************************************************************/

using std::next_permutation;

class BruteForceSim
{
	private:
	int numCities;
	CityGraph simGraph;
	double optPath;
	void CalcOptPath();
	public:
	BruteForceSim(int numCities);
	void RunSim();
	double GetOptPath();
};

#endif
