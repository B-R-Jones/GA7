#include <iostream>
#include <nlohmann/json.hpp>
#include "constructors.h"
#include "fitness.h"
#include "simSettings.h"

std::string getIndividualStrand(nlohmann::json individual)
{
	std::string strand{ "" };
	for (int chromCount = 0; chromCount < getChromosomeCount(); ++chromCount)
	{
		for (int geneCount = 0; geneCount < getGeneCount(); ++geneCount)
		{
			for (int baseCount = 0; baseCount < getBaseCount(); ++baseCount)
			{
				nlohmann::json chrom{ individual["chromosomes"].at(chromCount) };
				nlohmann::json gene{ chrom["genes"].at(geneCount) };
				nlohmann::json base{ gene["bases"].at(baseCount) };
				strand = strand + std::to_string(base.value("/baseValue"_json_pointer, -1));
			}
		}
	}
	return strand;
}

void fitnessEval(nlohmann::json& individual)
{
	std::string ind{ getIndividualStrand(individual) };
	std::string tar{ getTargetStrand() };
	double matches{ static_cast<double>(ind.size()) };
	double total{ static_cast<double>(tar.size()) };
	for (int i = 0; i < total; ++i)
	{
		//std::cout << "Individual: " << std::to_string(ind[i]) << std::endl;
		//std::cout << "Target: " << std::to_string(tar[i]) << std::endl;
		if (ind[i] != tar[i])
		{
			matches--;
		}
	}
	double evalScore{ matches / total };
	std::cout << "Eval Scorea: " << evalScore << std::endl;
	individual["fitness"] = evalScore;
}

void findFittest(nlohmann::json pop, nlohmann::json& parentA, nlohmann::json& parentB)
{
	nlohmann::json individual;
	nlohmann::json parentA_find;
	nlohmann::json parentB_find;
	nlohmann::json checkParent;
	for (int indCount = 0; indCount < getGenerationSize(); ++indCount)
	{
		individual = pop["individuals"].at(indCount);
		if (indCount == 0)
		{
			parentA_find = individual;
		}
		else if (indCount == 1)
		{
			parentB_find = individual;
		}
		else if (indCount > 1)
		{
			if (individual["fitness"] > parentA_find["fitness"])
			{
				checkParent = parentA_find;
				parentA_find = individual;
				if (checkParent["fitness"] > parentB_find["fitness"])
				{
					parentB_find = checkParent;
				}
			}
		}
	}
	parentA = parentA_find;
	parentB = parentB_find;
}