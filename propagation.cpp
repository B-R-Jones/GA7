#include <iostream>
#include <nlohmann/json.hpp>
#include "fitness.h"
#include "mutators.h"
#include "propagaton.h"
#include "simSettings.h"

nlohmann::json propagateGeneration(nlohmann::json parentA, nlohmann::json parentB, int choice)
{
	nlohmann::json pop;
	switch(choice)
	{
	case 0: pop = propGenM0(parentA, parentB);
		break;
	}
	return pop;
}

nlohmann::json propGenM0(nlohmann::json parentA, nlohmann::json parentB)
{
	nlohmann::json pop;
	for (int indCount = 0; indCount < getGenerationSize(); ++indCount)
	{
		nlohmann::json ind;
		ind["id"] = indCount;
		for (int chromCount = 0; chromCount < getChromosomeCount(); ++chromCount)
		{
			if (chromCount == 0)
			{
				ind["chromosomes"].push_back(parentA["chromosomes"].at(chromCount));
			}
			else
			{
				ind["chromosomes"].push_back(parentB["chromosomes"].at(chromCount));
			}
		}
		mutate(ind);
		fitnessEval(ind);
		pop["individuals"].push_back(ind);
	}
	return pop;
}