#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "constructors.h"
#include "simSettings.h"
#include "mutators.h"

void mutate(nlohmann::json& individual)
{
	for (int chromID = 0; chromID < getChromosomeCount(); ++chromID)
	{
		for (int geneID = 0; geneID < getGeneCount(); ++geneID)
		{
			for (int baseID = 0; baseID < getBaseCount(); ++baseID)
			{
				int chance = rand() % 100;
				if (chance < getMutationRate())
				{
					nlohmann::json chrom(individual["chromosomes"].at(chromID));
					nlohmann::json gene(chrom["genes"].at(geneID));
					nlohmann::json base(gene["bases"].at(baseID));
					//std::string site("C" + std::to_string(chromID) + "G" + std::to_string(geneID) + "B" + std::to_string(baseID));
					int prevVal(base["baseValue"]);
					//std::cout << "Base Value Pre-Mutation Site " << site << ": " << base["baseValue"] << std::endl;
					while (base["baseValue"] == prevVal)
					{
						//std::cout << "Mutating Site " << site << "..." << std::endl;
						base["baseValue"] = rand() % getBaseCount();
					}
					//std::cout << "Base Value Post-Mutation Site " << site << ": " << base["baseValue"] << std::endl;
					gene["bases"].at(baseID).update(base);
					chrom["genes"].at(geneID).update(gene);
					individual["chromosomes"].at(chromID).update(chrom);
				}
			}
		}
	}
	return;
}