#include <iostream>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>
#include <cmath>
#include "expression.h"
#include "simSettings.h"

double expressionValue(int base)
{
	double x(0);
	switch (base)
	{
		case 0:
			x = rand() % 25 + 1;
			break;
		case 1:
			x = rand() % 50 + 26;
			break;
		case 2:
			x  = rand() % 75 + 51;
			break;
		case 3:
			x  = rand() % 100 + 76;
			break;
	}
	x = x / 100;
	return x;
}

nlohmann::json geneExpression(nlohmann::json& individual)
{
	for (int chromCount = 0; chromCount < getChromosomeCount(); ++chromCount)
	{
		for (int geneCount = 0; geneCount < getGeneCount(); ++geneCount)
		{
			double score{ 0.0 };
			for (int baseCount = 0; baseCount < getBaseCount(); ++baseCount)
			{
				score = individual["chromosomes"].at(chromCount)["genes"].at(geneCount)["score"];
				score = score + expressionValue(individual["chromosomes"].at(chromCount)["genes"].at(geneCount)["bases"].at(baseCount)["baseValue"]);
			}
			individual["chromosomes"].at(chromCount)["genes"].at(geneCount)["score"] = score;
		}
	}
	return individual;
}

nlohmann::json geneExpressionOld(nlohmann::json& individual)
{
		for (int geneCount = 0; geneCount < getGeneCount(); ++geneCount)
		{
			double acc(individual["chromosome1"]["gene" + std::to_string(geneCount)]["Accumulation"]);
			for (int baseCount = 0; baseCount < getBaseCount(); ++baseCount)
			{
				int base(0);
				if (individual["chromosome0"]["gene" + std::to_string(geneCount)]["Activated"] == true)
				{
					base = individual["chromosome1"]["gene" + std::to_string(geneCount)]["base" + std::to_string(baseCount)];
					acc = acc + expressionValue(base);
					acc = std::round(acc * 100.0) / 100.0;
				}
			}
			individual["chromosome1"]["gene" + std::to_string(geneCount)]["Accumulation"] = acc;
		}
	return individual;
}

nlohmann::json cyclePass(nlohmann::json& pop)
{
	//nlohmann::json generation;
	//for (int cycleCount = 0; cycleCount < getCycleCount(); cycleCount++)
	//{
		for (int indCount = 0; indCount < getGenerationSize(); indCount++)
		{
			geneExpression(pop["individuals"].at(indCount));
		}
	//}
	return pop;
}