#include <iostream>
#include "../GenAlgSim.hpp"
#include "../CityGraph.hpp"

using std::cout;
using std::endl;

int main()
{
	cout << "testing genetic sim with:" << endl;
	cout << "Cities: 10" << endl;
	cout << "Tours per gen: 6" << endl;
	cout << "Generations: 2" << endl;
	cout << "percent Mutation: 0.5" << endl;

	GenAlgSim testSim(10, 6, 2, 0.5);

	return 0;
}
