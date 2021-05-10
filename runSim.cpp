#include <iostream>
#include <nlohmann/json.hpp>
#include "constructors.h"
#include "fitness.h"
#include "mutators.h"
#include "propagaton.h"
#include "simSettings.h"

nlohmann::json simPkg()
{
	nlohmann::json simPkg;
	nlohmann::json generations;
	nlohmann::json pop;
	for (int i = 0; i < getGenerationCount(); ++i)
	{
		std::cout << "Processing generation " << std::to_string(i) << "..." << std::endl;
		generations["id"] = i;
		if (i == 0)
		{
			pop = constructPopulationJson();
		}
		else
		{
			nlohmann::json parentA;
			nlohmann::json parentB;
			findFittest(pop, parentA, parentB);
			pop = propagateGeneration(parentA, parentB);
			processPopulationMutations(pop);
		};
		nlohmann::json cycles;
		cycles.push_back(runCycles(pop));
		generations["cycles"].push_back(cycles);
		simPkg.push_back(generations);
	}
	return simPkg;
}