#include "GenAlgSim.hpp"

//header comment goes here

GenAlgSim::GenAlgSim(int numCities, int numTours, int numGens, double percentMutation)
{
	this->numCities = numCities;
	this->numTours = numTours;
	this->numGens = numGens;
	this->percentMutation = percentMutation;

	this->simGraph.FillGraph(this->numCities); //populates graph with distances
	
	for(int i = 0; i < this->numCities; ++i)  //populates tourpath vector with default path.
	{ this->tourPath.push_back(i); }

}

void GenAlgSim::RunSim()
{
	//storage for respective elites.
	vector<int> permElite;
	vector<int> muteElite;

	//calculate cost of the default path, and store in optPath for comparisoni, counts as 1 permutation.
	for(int i = 0; i < this->numCities; ++i)
	{
		if((i + 1) != this->numCities)
		{
			this->optPath += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(i + 1));
		}
		else
		{
			this->optPath += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(0));
		}
	}

	std::cout << "calculated default path cost: line 38." << std::endl;
	
	//assigns tourpath as the starting elite value for both types of transformation.
	this->permElite = this->tourPath;
	this->muteElite = this->tourPath;
	
	//get permutation/mutation split for each generation
	int numMutations = this->numTours * this->percentMutation;
	int numPermutations = (this->numTours - numMutations) - 1;
	
	std::cout << "stored number of permutations and mutations per generation: line 48." << std::endl;

	//loop n times where n is the number of generations decided by the user.
	for(int g = 0; g < this->numGens; ++g)
	{
		//assigns elite at start of generations calculations
		this->tourPath.assign(this->permElite.begin(), this->permElite.end());

		//loop through permutation portion of tours
		for(int p = 0; p < numPermutations; ++p)
		{
			PermutatePath(); //get the next permutation
			CalcOptPath(1); //calculate cost, and store permutation if optimal.
		}
		
		//assigns elite at start of generations calculations
		this->tourPath.assign(this->muteElite.begin(), this->muteElite.end());

		//loop through mutation portion of tours
		for(int m = 0; m < numMutations; ++m)
		{
			MutatePath(); //get net mutation
			CalcOptPath(2); //calculates cost, and store mutation if optimal
		}
	}

}

void GenAlgSim::CalcOptPath(int caseNum)
{
	//create temp storage for potential path cost
	double costStore = 0;

	for(int i = 0; i < this->numCities; ++i)
        {
		if((i + 1) != this->numCities)
		{
                	costStore += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(i + 1));
                }
                else
                {
			costStore += this->simGraph.GetCityDistance(this->tourPath.at(i), this->tourPath.at(0));
 		}
	}

	if(costStore < GetOptPath())
	{
		this->optPath = costStore;

		switch(caseNum)
		{
			case 1: //its a permutation
			this->permElite.assign(this->tourPath.begin(), this->tourPath.end());;
			break;

			case 2: //its a mutation
			this->muteElite.assign(this->tourPath.begin(), this->tourPath.end());
			break;

			default:
			throw "how did you break this?";
			break;
		}
	}
}

void GenAlgSim::MutatePath()
{
	//randomly select two cities within the path, and swap them.
	
	std::random_device rand; //generates seed for random num generator
	std::mt19937 gen(rand()); //Standard mersenne twister engine seeded with the above random device.
	std::uniform_int_distribution<> distribute(1, (this->numCities - 1)); //generates random ints uniformly distributed along a closed range.
	
	int swapHolderA;
	int swapHolderB;
	int indexA = distribute(gen);
	int indexB = distribute(gen);

	swapHolderA = this->tourPath.at(indexA);
	swapHolderB = this->tourPath.at(indexB);

	this->tourPath.erase(this->tourPath.begin() + indexA);
	this->tourPath.insert((this->tourPath.begin() + indexA), swapHolderB);

	this->tourPath.erase(this->tourPath.begin() + indexB);
	this->tourPath.insert((this->tourPath.begin() + indexB), swapHolderA);

	//while avoiding swaps that have already been made?
}

void GenAlgSim::PermutatePath()
{ next_permutation((this->tourPath.begin() + 1), this->tourPath.end());  }

double GenAlgSim::GetOptPath()
{ return this->optPath; }
