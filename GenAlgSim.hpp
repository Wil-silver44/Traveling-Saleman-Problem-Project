#ifndef GENALGSIM_HPP
#define GENALGSIM_HPP
#include <algorithm>
#include <vector>
#include <random>
#include "CityGraph.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: GenAlgSim.hpp
 *   Assignment number: Project 3
 *
 *   Other comments regarding the file - defines the attributes and methods
 *   for running a Geneticly inspired algorithm for the traveling salesman problem.
 *
 ***************************************************************/

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
        vector<int> permElite; //storage for respective elites per generation.
	vector<int> muteElite;
	CityGraph simGraph;
	double optPath;
	void CalcOptPath(int caseNum);
	void MutatePath();
	void PermutatePath();
	public:
	GenAlgSim(int numCities, int numTours, int numGens, double percentMutation);
	void RunSim();
	double GetOptPath();

};

#endif
