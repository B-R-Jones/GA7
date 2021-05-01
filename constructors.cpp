#include <iostream>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>
#include "simSettings.h"
#include "creators.h"

nlohmann::json constructBaseJson(int baseID = 0, int baseCount = getBaseCount())
{
    if (baseCount < 1)
    {
        std::cout << "Too few bases requested\n";
        return 0;
    }
    nlohmann::json base;
    base["id"] = baseID;
    base["baseValue"] = createBase();
    return base;
}

nlohmann::json constructGeneJson(int geneID = 0)
{
    nlohmann::json gene;
    gene["id"] = geneID;
    for (int baseID = 0; baseID < getBaseCount(); ++baseID)
    {
        gene["bases"].push_back(constructBaseJson(baseID));
        gene["score"] = 0.0;

    }
    if (checkChromLoc() == 0)
    {
        gene["activated"] = true;
        //gene["activate_score"];
    }
    else if (checkChromLoc() == 1)
    {
        gene["accumulation"] = 0.0;
        //gene["accumulation_score"];
    }

    return gene;
}

nlohmann::json constructChromosomeJson(int chromID = -1)
{
    nlohmann::json chromosome;
    chromosome["id"] = chromID;
    for (int geneID = 0; geneID < getGeneCount(); ++geneID)
    {
        chromosome["genes"].push_back(constructGeneJson(geneID));
    }
    return chromosome;
}

nlohmann::json constructIndividualJson(int indID = 0)
{
    nlohmann::json individual;
    individual["id"] = indID;
    for (int chromID = 0; chromID < getChromosomeCount(); ++chromID)
    {
        setChromLoc(chromID);
        individual["chromosomes"].push_back(constructChromosomeJson(chromID));
    }
    return individual;
}

nlohmann::json constructPopulationJson()
{
    nlohmann::json population;
    for (int indID = 0; indID < getGenerationSize(); ++indID)
    {
        population["individuals"].push_back(constructIndividualJson(indID));
    }
    return population;
}