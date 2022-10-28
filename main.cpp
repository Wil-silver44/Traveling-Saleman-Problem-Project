#include "SimulationRunner.hpp"

/***************************************************************
 *   Student Name: Wilver Santos
 *   File Name: main.cpp
 *   Assignment number: Project 3
 *
 *   Other comments regarding the file - driver code that is executed.
 *
 ***************************************************************/

int main()
{
	SimulationRunner someRunner;
	someRunner.RunBruteForce();
	someRunner.RunGenetic();
	someRunner.PrintResult();
	return 0;
}
