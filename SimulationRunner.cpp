#include "SimulationRunner.hpp"

//header comment goes here

SimulationRunner::SimulationRunner()
{
	int numHolder;
	double percentHolder;
	cout << "Please enter the following values:" << endl;
	cout << "The number of cities to run: ";
	cin >> numHolder;
	SetNumCities(numHolder);

	cout << "\nHow many individual tours are in a given generation: ";
	cin >> numHolder;
	SetNumTours(numHolder);

	cout << "\nHow many generations to run: ";
	cin >> numHolder;
	SetNumGenerations(numHolder);

	cout << "\nWhat percentage of a generation should be comprised of mutated tours: ";
	cin >> percentHolder;
	SetPercentMutation(percentHolder);
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
	BruteForceSim testSim(GetNumCities(), GetNumTours());
	testSim.RunSim();
        this->bruteForceOptPath = testSim.GetOptPath();	
}

void SimulationRunner::RunGenetic()
{
	cout << "Totally running genetic ;p" << endl;
}

void SimulationRunner::PrintResult()
{
	cout << "The number of cities run: " << GetNumCities() << endl;
	cout << "Optimal cost of Brute force: " << this->bruteForceOptPath << endl;
        cout << "Time the brute force algorithm took to run: IMPLEMENT BRUTEFORCE" << endl;
	cout << "Optimal cost of ga: IMPLEMENT GENETIC" << endl;
	cout << "Time the ga took to run: IMPLEMENT GENETIC" << endl;
	cout << "Percent of optimal that ga Produced: IMPLEMENT GENETIC" <<endl;	
}
