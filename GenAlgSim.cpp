#include "GenAlgSim.hpp"

//header comment goes here

GenAlgSim::GenAlgSim(int numCities, int numTours, int numGens, double percentMutation)
{
	this->numCities = numCities;
	this->numTours = numTours;
	this->numGens = numGens;
	this->percentMutation = percentMutation;

	this->simGraph.FillGraph(this->numCities); //populates graph with distances
	
	for(int i = 0; i < this->numCities; ++i)  //populates tourpath vector with default path.
	{ this->tourPath.push_back(i); }

}

void GenAlgSim::RunSim()
{
	//calculate cost of the default path, and store in optPath for comparison.
	for(int i = 0; i < this->numCities; ++i)
	{
		if((i + 1) != this->numCities)
		{
			this->optPath += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(i + 1));
		}
		else
		{
			this->optPath += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(0));
		}
	}
	
	
	//get permutation/mutation split for each generation
	int numMutations = this->numTours * this->percentMutation;
	int numPermutations = (this->numTours - numMutations) - 1;

	//loop n times where n is the number of generations decided by the user.
	for(int g = 0; g < this->numGens; ++g)
	{
		//loop through permutation portion of tours
		for(int p = 0; p < numPermutations; ++p)
		{

		}
		
		//loop through mutation portion of tours
		for(int m = 0; m < numMutations; ++m)
		{

		}
	}

}

void GenAlgSim::CalcOptPath()
{
	//create temp storage for potential path cost
	double costStore = 0;

	for(int i = 0; i < this->numCities; ++i)
        {
		if((i + 1) != this->numCities)
		{
                	costStore += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(i + 1));
                }
                else
                {
			costStore += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(0));
 		}
	}

	if(costStore < this->optPath)
	{
		this->optPath = costStore;
	}
}

void GenAlgSim::MutatePath()
{

}

void GenAlgSim::PermutatePath()
{ next_permutation((this->tourPath.begin() + 1), this->tourPath.end());  }

double GenAlgSim::GetOptPath()
{ return this->optPath; }
