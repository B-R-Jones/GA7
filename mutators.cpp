#include <iostream>
#include <string>
#include "simSettings.h"
#include "creators.h"
#include "mutators.h"

std::string mutateDNA(std::string strand)
{
	//std::cout << "Old sequence: " << strand << "\n";
	for (uint16_t i = 0; i < strand.length(); i++)
	{
		if (rand() % 100 <= getMutationRate())
		{
			//std::cout << "Index changed: " << i << "\n";
			strand.replace(i, 1, std::to_string(createBase()));
		}
	}
	//std::cout << "New sequence: " << strand << "\n";
	return strand;
	
}

//std::vector<std::string> mutateGeneration(std::vector<std::string> generation)
//{
//	std::vector<std::string> mutatedGeneration(0);
//	for (int i = 0; i < generation.capacity(); i++)
//	{
//		mutatedGeneration.push_back(mutateDNA(generation[i]));
//	}
//	return mutatedGeneration;
//}