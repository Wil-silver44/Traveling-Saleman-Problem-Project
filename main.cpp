#include "SimulationRunner.hpp"

int main()
{
	SimulationRunner someRunner;
	someRunner.RunBruteForce();
	someRunner.RunGenetic();
	someRunner.PrintResult();
	return 0;
}
