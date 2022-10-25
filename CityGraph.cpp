#include "CityGraph.hpp"

// header comment goes here

CityGraph::CityGraph()
{
	this->fileReader.open(DISTANCE_FILE);
}

void CityGraph::FillGraph(int numCities)
{
	if(this->fileReader.is_open())
	{
		double dataHolder = 0;

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
