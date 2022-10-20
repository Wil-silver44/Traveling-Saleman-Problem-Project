#include <iostream>
#include <iomanip>
#include "../CityGraph.hpp"

using std::cout;
using std::endl;
using std::setprecision;

int main()
{
	cout << "creating Citygraph object using distances.txt, and generating 8 cities." << endl;

	CityGraph testGraph("distances.txt", 8);

	cout << "created graph, printing data:" << endl;

	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			cout << setprecision(4) << testGraph.GetCityDistance(i,j) << " ";
		}

		cout << endl;
	}
	
	cout << "Operation complete." << endl;
	return 0;
}
