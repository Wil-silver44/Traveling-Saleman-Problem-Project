#include <iostream>
#include "../GenAlgSim.hpp"
#include "../CityGraph.hpp"

using std::cout;
using std::endl;

int main()
{
	cout << "testing genetic sim with:" << endl;
	cout << "Cities: 10" << endl;
	cout << "Tours per gen: 10" << endl;
	cout << "Generations: 10" << endl;
	cout << "percent Mutation: 0.5" << endl;

	GenAlgSim testSim(10, 10, 10, 0.5);

	cout << "attempting to run sim..." << endl << endl;

	testSim.RunSim();

	cout << "Simulation ran. optimal cost: " << testSim.GetOptPath() << endl;

	return 0;
}
