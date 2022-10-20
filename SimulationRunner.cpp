#include "SimulationRunner.hpp"

//header comment goes here

SimulationRunner::SimulationRunner()
{
	cout << "Please enter the following values:" << endl;
	cout << "The number of cities to run: ";
	cin >> this->numCities;

	cout << "\nHow many individual tours are in a given generation: ";
	cin >> this->numTours;

	cout << "\nHow many generations to run: ";
	cin >> this->numGenerations;

	cout << "\nWhat percentage of a generation should be comprised of mutated tours: ";
	cin >> this->percentMutation;
}

int SimulationRunner::GetNumCities()
{ return this->numCities; }

void SimulationRunner::RunBruteForce()
{
	cout << "Totally running brute force ;p" << endl;
}

void SimulationRunner::RunGenetic()
{
	cout << "Totally running genetic ;p" << endl;
}

void SimulationRunner::PrintResult()
{
	cout << "The number of cities run: " << GetNumCities() << endl;
	cout << "Optimal cost of Brute force: IMPLEMENT BRUTEFORCE" << endl;
        cout << "Time the brute force algorithm took to run: IMPLEMENT BRUTEFORCE" << endl;
	cout << "Optimal cost of ga: IMPLEMENT GENETIC" << endl;
	cout << "Time the ga took to run: IMPLEMENT GENETIC" << endl;
	cout << "Percent of optimal that ga Produced: IMPLEMENT GENETIC" <<endl;	
}
