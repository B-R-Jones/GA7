#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>
#include "simSettings.h"
#include "creators.h"
#include "expression.h"
#include "constructors.h"

//using nlohmann::json;
nlohmann::json constructBaseJson(int baseID, int baseCount)
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

nlohmann::json constructGeneJson(int geneID)
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
    }
    else if (checkChromLoc() == 1)
    {
        gene["accumulation"] = 0.0;
    }
    return gene;
}

nlohmann::json constructChromosomeJson(int chromID)
{
    nlohmann::json chromosome;
    chromosome["id"] = chromID;
    for (int geneID = 0; geneID < getGeneCount(); ++geneID)
    {
        chromosome["genes"].push_back(constructGeneJson(geneID));
    }
    return chromosome;
}

nlohmann::json constructIndividualJson(int indID)
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

nlohmann::json constructCycleJson(nlohmann::json& pop, int cycleID)
{
    nlohmann::json cycle;
    cycle["id"] = cycleID;
    if (cycleID > 0)
    {
        cycle["population"].push_back(cyclePass(pop));
    }
    else 
    {
        cycle["population"].push_back(pop);
    }
    return cycle;
}

nlohmann::json runCycles(nlohmann::json& pop)
{
    //nlohmann::nlohmann::json pop;
    nlohmann::json cycles;
    for (int cycleID = 0; cycleID < getCycleCount(); ++cycleID)
    {
        nlohmann::json cycle(constructCycleJson(pop, cycleID));
        cycles.push_back(cycle);
    }
    return cycles;
}

//nlohmann::json constructGenJson(nlohmann::json& pop, int genID = 0)
//{
//    //nlohmann::json generation;
//    //generation["id"] = genID;
//    //generation["id"].at(genID)["cycles"].push_back(runCycles(pop));
//    return 0;
//}