#include <string>
#include <iostream>
#include <vector>
#include "simSettings.h"
#include "creators.h"
#include "mutators.h"

std::vector<std::string> generationVector(0);

int createBase()
{
	int base{ rand() % getBaseCount() };
	return base;
}

std::string createGene()
{
	std::string gene{ "" };
	for (int baseIncrement = 0; baseIncrement < getBaseCount(); baseIncrement++)
	{
		gene += std::to_string(createBase());
	}
	return gene;
}

std::string createChromosome()
{
	std::string chromosome{ "" };
	for (int geneIncrement = 0; geneIncrement < getGeneCount(); geneIncrement++)
	{
		chromosome += createGene();
	}
	return chromosome;
}

std::string createIndividual()
{
	std::string individual{ "" };
	for (int chromosomeIncrement = 0; chromosomeIncrement < getChromosomeCount(); chromosomeIncrement++)
	{
		individual += createChromosome();
	}
	return individual;
}

void createPopulation()
{
	for (int i = 0; i < getGenerationSize(); i++)
	{
		generationVector.push_back(createIndividual());
	}
}

std::string returnGenerationIndividual(int individualIndex)
{
	return generationVector[individualIndex];
}