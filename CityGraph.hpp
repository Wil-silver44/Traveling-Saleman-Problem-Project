#ifndef CITYGRAPH_HPP
#define CITYGRAPH_HPP
#include <fstream>
#include <string>

 /***************************************************************
  *   Student Name: Wilver Santos
  *   File Name: CityGraph.hpp
  *   Assignment number: Project 3
  *
  *   Other comments regarding the file - defines the attributes and methods 
  *   for an adjacency-matrix based graph weighted with doubles representing distances between cities
  *
  ***************************************************************/

using std::string;
using std::ifstream;
using std::getline;

static const string DISTANCE_FILE = "distances.txt"; //the name of the file containing distances

class CityGraph
{
	private:
	static const int MATRIX_MAX = 20; //maximum height and width of the 2d array.
	double graphMatrix[MATRIX_MAX][MATRIX_MAX];
	ifstream fileReader;
	public:
	CityGraph();
	void FillGraph(int numCities);
	double GetCityDistance(int indexA, int indexB);
};

#endif
