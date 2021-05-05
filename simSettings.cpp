#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include "simSettings.h"
#include "creators.h"

// Creation management methods below
int baseCount{ 4 };
int getBaseCount()
{
	return baseCount;
}
bool setBaseCount(unsigned char newBaseCount)
{
	if (isdigit((unsigned char)newBaseCount))
	{
		baseCount = newBaseCount - '0';
		std::cout << "New base number set to: " << newBaseCount << "\n";
		return true;
	}
	std::cout << "New base count could not be set!\n";
	return false;
}

int geneCount{ 8 };
int getGeneLength()
{
	return getBaseCount();
}
int getGeneCount()
{
	return static_cast<const int>(geneCount);
}
bool setGeneCount(unsigned char newGeneCount)
{
	if (isdigit((unsigned char)newGeneCount))
	{
		geneCount = newGeneCount - '0';
		std::cout << "New gene count set to: " << newGeneCount << "\n";
		return true;
	}
	std::cout << "New gene count could not be set!\n";
	return false;
}

int chromosomeCount{ 2 };
int getChromosomeLength()
{
	return (getChromosomeCount() * getGeneCount() * getBaseCount())/2;
}
int getChromosomeCount()
{
	return static_cast<const int>(chromosomeCount);
}
bool setChromosomeCount(unsigned char newChromosomeCount)
{
	if (isdigit((unsigned char)newChromosomeCount))
	{
		chromosomeCount = newChromosomeCount - '0';
		std::cout << "New chromosome count set to: " << newChromosomeCount << "\n";
		return true;
	}
	std::cout << "New chromosome count could not be set!\n";
	return false;
}

int chromLoc{ 0 };
int getChromLoc()
{
	return chromLoc;
}

void resetChromLoc()
{
	chromLoc = 0;
}

int checkChromLoc()
{
	if (chromLoc > 1)
	{
		resetChromLoc();
		return -1;
	}
	return chromLoc;
}

void updateChromLoc()
{
	chromLoc++;
}

void setChromLoc(int chromLocOverride)
{
	chromLoc = chromLocOverride;
}

//int strandLength{ 64 };
int strandLength{ getChromosomeCount() * getGeneCount() * getBaseCount() };
int getStrandLength()
{
	return static_cast<const int>(strandLength);
	//return strandLength;
}
void setStrandLength()
{
	strandLength = getChromosomeCount() * getGeneCount() * getBaseCount();
}

//int individualCount{ 10 };
//int getIndividualCount()
//{
//	return static_cast<const int>(individualCount);
//}

// return generation vector elements here
int generationSize{ 10 };
//void setInitialGenerationSize()
//{
//	//std::vector<std::string> generationVector(50);
//}

int getGenerationSize()
{
	//return static_cast<const int>(generationVector.capacity());
	return static_cast<const int>(generationSize);
}

int cycleCount{ 10 };
int getCycleCount()
{
	return static_cast<const int>(cycleCount);
}




//std::vector<int>::iterator generationIndex;
//int getGenerationIndex()
//{
//	return static_cast<const int>(generationVector.capacity());
//}

// Time management methods below; namespace chrono required
using namespace std::chrono;
	milliseconds stamp1 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	milliseconds getStamp1()
	{
		return stamp1;
	}
	milliseconds start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	milliseconds getStart()
	{
		return start;
	}
	milliseconds end = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	milliseconds getEnd()
	{
		return end;
	}
	int runTime()
	{
		end = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		return end.count() - start.count();
	}
	void setTime()
	{
		milliseconds stamp2 = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		//int diff = stamp2.count() - stamp1.count();
		int diff = stamp1.count();
		srand(diff);
		std::cout << "Time differential: " << diff << "\n";
	}

	// Mutation management methods below
	double mutationRate{ 5.0 };
	double getMutationRate()
	{
		return static_cast<const double>(mutationRate);
	}
	bool setMutationRate(unsigned char newMutationRate)
	{
		if (isdigit((unsigned char)newMutationRate))
		{
			if (newMutationRate > 100)
			{
				newMutationRate = 100;
			}
			mutationRate = newMutationRate - '0';
			std::cout << "New mutation rate set to: " << newMutationRate << "\n";
			return true;
		}
		std::cout << "New mutation rate could not be set!\n";
		return false;
	}
