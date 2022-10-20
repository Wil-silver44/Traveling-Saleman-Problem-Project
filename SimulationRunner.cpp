#include "SimulationRunner.hpp"

//header comment goes here

SimulationRunner::SimulationRunner()
{
	cout << "Please enter the following values:" << endl;
	cout << "The number of cities to run: ";
	SetNumCities(cin);

	cout << "\nHow many individual tours are in a given generation: ";
	SetNumTours(cin);

	cout << "\nHow many generations to run: ";
	SetNumGenerations(cin);

	cout << "\nWhat percentage of a generation should be comprised of mutated tours: ";
	SetPercentMutation(cin);
}

//Mutators
void SimulationRunner::SetNumCities(int someNum)
{ this->numCities = someNum; }

void SimulationRunner::SetNumTours(int someNum)
{ this->numTours = someNum; }

void SimulationRunner::SetNumGenerations(int someNum)
{ this->numGenerations = someNum; }

void SimulationRunner::SetPercentMutation(double somePercent)
{ this->percentMutation = somePercent; }

//Accessors
int SimulationRunner::GetNumCities()
{ return this->numCities; }

int SimulationRunner::GetNumTours()
{ return this->numTours; }

int SimulationRunner::GetNumGenerations()
{ return this->numGenerations; }

double SimulationRunner::GetPercentMutation()
{ return this->percentMutation; }

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
