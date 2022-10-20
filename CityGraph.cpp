#include "CityGraph.hpp"

// header comment goes here

CityGraph::CityGraph(string fileName, int numCities)
{
	this->fileReader.open(fileName);
	if(this->fileReader.is_open())
	{
		double dataHolder = 0.0;
		
		for(int i = 0; i < numCities; ++i)
		{
			for(int j = 0; j < numCities; ++j)
			{
				if(i == j) //a cities distance from itself is 0.
				{
					this->graphMatrix[i][j] = 0.0;
				}
				else
				{
					this->fileReader >> dataHolder;
					this->graphMatrix[i][j] = dataHolder;
				}
			}
		}
	}

	this->fileReader.close();
}

double CityGraph::GetCityDistance(int indexA, int indexB)
{ return this->graphMatrix[indexA][indexB]; }
