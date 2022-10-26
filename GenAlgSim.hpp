#ifndef GENALGSIM_HPP
#define GENALGSIM_HPP
#include <algorithm>
#include <vector>
#include "CityGraph.hpp"

//header comment goes here

using std::next_permutation;
using std::vector;

class GenAlgSim
{
	private:
	int numCities;
	int numTours;	//number of tours to generate for a given generation
	int numGens;	//the number of generations
	double percentMutation;	//the percentage of a given generation that are mutated tours rather than permutated.
	vector<int> tourPath;	//storage for a given tourPath
	CityGraph simGraph;
	double optPath;
	void CalcOptPath();
	void MutatePath();
	void PermutatePath();
	public:
	GenAlgSim(int numCities, int numTours, int numGens, double percentMutation);
	void RunSim();
	double GetOptPath();

};

#endif