#include <iostream>
#include <vector>
//#include <json-develop/json-develop/single_include/nlohmann/json.hpp>
//#include <nlohmann/json.hpp>
#include "simSettings.h"
#include "parsers.h"

int chromosomeCounter{ 0 };
int geneCounter{ 0 };
int baseCounter{ getBaseCount() };
int mainIndex{ 0 };

using namespace std;
vector<vector<vector<string> > > readDNA(string strand) // Requires a whole strand constructed through readDNA
{
	for (int i = 0; i < strand.length(); i++)
	{
	//chromosome vector below 
	std::vector<std::vector<std::vector<std::string>>> chromosomeVector;
	for (chromosomeCounter = 0; chromosomeCounter < getChromosomeCount(); chromosomeCounter++)
	{
		//gene vector created below
		std::vector<std::vector<std::string>> geneVector;
		for (int geneCounter = 0; geneCounter < getGeneCount(); geneCounter++)
		{
			//base vector created below
			std::vector<std::string> baseVector(getBaseCount());
			for (int baseCounter = 0; baseCounter < getBaseCount(); baseCounter++)
			{
				//std::cout << strand[i] << "\n";
				baseVector[baseCounter]=strand[i];
				i++;
			}
			geneVector.push_back(baseVector);
			baseVector.clear();
		}
		chromosomeVector.push_back(geneVector);
		geneVector.clear();
	}
	return chromosomeVector;
	}
}

void outputStrandInfo(vector<vector<vector<string> > > strand)
{
	for (int i = 0; i < strand.size(); i++)
	{
		std::cout << "Chromosome: " << i+1 << "\n";
		for (int j = 0; j < strand[0].size(); j++)
		{
			std::cout << "Gene " << j+1 << ": ";
			for (int k = 0; k < strand[0][0].size(); k++)
			{
				std::cout << strand[i][j][k];
			}
			std::cout << "\n";
		}
	}
}

void ouptutPopInfo(vector<vector<vector<vector<string> > > > testPop)
{
	for (int i = 0; i < testPop.size(); i++)
	{
		std::cout << "Individual " << i + 1 << ": \n";
		outputStrandInfo(testPop[i]);
	}
}