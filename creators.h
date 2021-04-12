#pragma once
#include <vector>

int createBase();
std::string createGene();
std::string createChromosome();
std::string createIndividual();
//std::string* generationArray = new std::string[getIndividualCount()];

void createPopulation();
std::string returnGenerationIndividual(int x);