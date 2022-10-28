#include "SimulationRunner.hpp"

//header comment goes here

SimulationRunner::SimulationRunner()
{
	int numHolder = -10;
	double percentHolder = -10;
	cout << "Please enter the following values:" << endl;
	
	while(numHolder < 1 || numHolder > 20)
	{
		cout << "The number of cities to run[1,20]: ";
		cin >> numHolder;
	}

	SetNumCities(numHolder);

	numHolder = -10;
	
	while(numHolder < 10 || numHolder > 500)
	{
		cout << "\nHow many individual tours are in a given generation[10,500]: ";
		cin >> numHolder;
		SetNumTours(numHolder);
	}
	
	numHolder = -10;

	while(numHolder < 10 || numHolder > 500)
	{
		cout << "\nHow many generations to run[10,500]: ";
		cin >> numHolder;
		SetNumGenerations(numHolder);
	}

	while(percentHolder < 0.0 || percentHolder > 1.0)
	{
		cout << "\nWhat percentage of a generation should be comprised of mutated tours[0.0,1.0]: ";
		cin >> percentHolder;
		SetPercentMutation(percentHolder);
	}
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
	BruteForceSim testSim(GetNumCities());
	this->timeKeeper.start();
	testSim.RunSim();
	this->timeKeeper.stop();
	this->bruteForceRunTime = timeKeeper.elapsed();
        this->bruteForceOptPath = testSim.GetOptPath();	
}

void SimulationRunner::RunGenetic()
{
	GenAlgSim testGA(GetNumCities(), GetNumTours(), GetNumGenerations(), GetPercentMutation());
	this->timeKeeper.start();
	testGA.RunSim();
	this->genAlgOptPath = testGA.GetOptPath();
	this->timeKeeper.stop();
	this->genAlgRunTime = timeKeeper.elapsed();
}

void SimulationRunner::PrintResult()
{
	cout << "The number of cities run: " << GetNumCities() << endl;
	cout << "Optimal cost of Brute force: " << this->bruteForceOptPath << endl;
        cout << "Time the brute force algorithm took to run: " << this->bruteForceRunTime << "s" << endl;
	cout << "Optimal cost of ga: " << this->genAlgOptPath << endl;
	cout << "Time the ga took to run: " << this->genAlgRunTime << "s"  << endl;
	cout << "Percent of optimal that ga Produced: " << ((this->genAlgOptPath / this->bruteForceOptPath) * 100.0) << "%" << endl;	
}
