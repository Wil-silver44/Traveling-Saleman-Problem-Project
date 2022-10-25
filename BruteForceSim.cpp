#include "BruteForceSim.hpp"
#include <iostream>

//header comment goes here

BruteForceSim::BruteForceSim(int numCities, int numTours)
{
	this->numCities = numCities;
	this->numTours = numTours;
	this->optPath = 9999;	
}

void BruteForceSim::RunSim()
{
	this->simGraph.FillGraph(this->numCities);
	CalcOptPath();
}

double BruteForceSim::GetOptPath()
{ return this->optPath; }

void BruteForceSim::CalcOptPath()
{
	//create path holder, and then insert default path
	int someTour[this->numCities];
	double pathStore = 0;

	for(int i = 0; i < this->numCities; ++i)
	{
		someTour[i] = i;
	}

	while(next_permutation(someTour, someTour + this->numCities))
	{

		for(int i = 0; i < this->numCities; ++i)
		{
			if((i + 1) != this->numCities)
			{
				pathStore += this->simGraph.GetCityDistance(someTour[i], someTour[i + 1]);
			}
			else

			{
				pathStore += this->simGraph.GetCityDistance(someTour[i], someTour[0]);
			}
		}

		if(pathStore < this->optPath)
		{
			this->optPath = pathStore;
			std::cout << "optimal path is: [";
			
			for(int u = 0; u < this->numCities; ++u)
			{
				std::cout << " ";
				std::cout << someTour[u];
			}
			
			std::cout << " ]" << std::endl;

			pathStore = 0;
		}

		else
		{
			pathStore = 0;
		}
	}
}
