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

nlohmann::json geneExpression(nlohmann::json individual)
{
	for (int cycleCount = 0; cycleCount < getCycleCount(); ++cycleCount)
	{
		for (int geneCount = 0; geneCount < getGeneCount(); ++geneCount)
		{
			//double acc(0);
			double acc(individual["chromosome1"]["gene" + std::to_string(geneCount)]["Accumulation"]);
			for (int baseCount = 0; baseCount < getBaseCount(); ++baseCount)
			{
				//std::cout << "Test: " << individual["chromosome0"]["gene" + std::to_string(geneCount)]["Activated"] << "\n";
				int base(0);
				if (individual["chromosome0"]["gene" + std::to_string(geneCount)]["Activated"] == true)
				{
					base = individual["chromosome1"]["gene" + std::to_string(geneCount)]["base" + std::to_string(baseCount)];
					//individual["chromosome1"]["gene" + std::to_string(geneCount)]["Accumulation"] = individual["chromosome1"]["gene" + std::to_string(geneCount)]["Accumulation"] + expressionValue(individual["chromosome1"]["gene" + std::to_string(geneCount)]["base" + std::to_string(baseCount)]);
					acc = acc + expressionValue(base);
					acc = std::round(acc * 100.0) / 100.0;
				}
			}
			//individual["chromosome1"]["gene" + std::to_string(geneCount)].erase("Accumulation");
			individual["chromosome1"]["gene" + std::to_string(geneCount)]["Accumulation"] = acc;
			//std::cout << "Expressed: " << individual["chromosome1"]["gene0"]["Accumulation"] << "\n";
		}
	}
	return individual;
}