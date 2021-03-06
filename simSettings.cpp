#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <nlohmann/json.hpp>
#include "constructors.h"
#include "simSettings.h"

// Creation management methods below
int baseCount{ 4 };
int getBaseCount()
{
	return static_cast<const int>(baseCount);
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

// Deprecated Strand methods
int strandLength{ getChromosomeCount() * getGeneCount() * getBaseCount() };
int getStrandLength()
{
	return static_cast<const int>(strandLength);
}
void setStrandLength()
{
	strandLength = getChromosomeCount() * getGeneCount() * getBaseCount();
}

// return generation vector elements here
int generationCount{ 10 };
int getGenerationCount()
{
	return static_cast<const int>(generationCount);
}

int generationSize{ 10 };
int getGenerationSize()
{
	return static_cast<const int>(generationSize);
}

int cycleCount{ 10 };
int getCycleCount()
{
	return static_cast<const int>(cycleCount);
}

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

// Target management methods below
nlohmann::json target{ constructIndividualJson() };
std::string getTargetStrand()
{
	std::string strand{ "" };
	for (int chromCount = 0; chromCount < getChromosomeCount(); ++chromCount)
	{
		for (int geneCount = 0; geneCount < getGeneCount(); ++geneCount)
		{
			for (int baseCount = 0; baseCount < getBaseCount(); ++baseCount)
			{
				nlohmann::json chrom{ target["chromosomes"].at(chromCount) };
				nlohmann::json gene{ chrom["genes"].at(geneCount) };
				nlohmann::json base{ gene["bases"].at(baseCount) };
				strand = strand + std::to_string(base.value("/baseValue"_json_pointer, -1));
			}
		}
	}
	return strand;
}