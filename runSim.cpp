#include <iostream>
#include <iomanip>
#include <fstream>
#include <nlohmann/json.hpp>
#include "constructors.h"
#include "fitness.h"
#include "mutators.h"
#include "propagaton.h"
#include "simSettings.h"

nlohmann::json simPkg()
{
	nlohmann::json simPkg;
	nlohmann::json pop;
	for (int i = 0; i < getGenerationCount(); ++i)
	{
		std::cout << "Processing generation " << std::to_string(i) << "..." << std::endl;
		nlohmann::json generation;
		generation["id"] = i;
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
		runGenCycles(generation, pop);
		std::ofstream genFeed("C:/Users/brent/source/repos/GA7/testing/json/sim/simGen" + std::to_string(i) + ".json");
		genFeed << std::setw(4) << generation << std::endl;
		simPkg["generations"].push_back(generation);
	}
	return simPkg;
}