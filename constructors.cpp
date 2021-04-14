#include <iostream>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>
#include "simSettings.h"
#include "creators.h"


nlohmann::json constructGeneJson()
{
    nlohmann::json gene;
    for (int i = 0; i < getBaseCount(); i++)
    {
        gene["base" + std::to_string(i)] = createBase();
    }
    return gene;
}

nlohmann::json constructChromosomeJson()
{
    nlohmann::json chromosome;
    for (int i = 0; i < getGeneCount(); ++i)
    {
        for (int j = 0; j < getBaseCount(); ++j)
        {
            chromosome["gene" + std::to_string(i)]["base" + std::to_string(j)] = createBase();
        }
    }

    return chromosome;
}

nlohmann::json constructIndividualJson()
{
    nlohmann::json individual;
    for (int chromosomeCount = 0; chromosomeCount < getChromosomeCount(); ++chromosomeCount)
    {
        for (int geneCount = 0; geneCount < getGeneCount(); ++geneCount)
        {
            for (int baseCount = 0; baseCount < getBaseCount(); ++baseCount)
            {
                individual["chromosome" + std::to_string(chromosomeCount)]["gene" + std::to_string(geneCount)]["base" + std::to_string(baseCount)] = createBase();
                if (chromosomeCount == 0)
                {
                    individual["chromosome" + std::to_string(chromosomeCount)]["gene" + std::to_string(geneCount)]["Activated"] = true;
                } else if (chromosomeCount == 1)
                {
                    individual["chromosome" + std::to_string(chromosomeCount)]["gene" + std::to_string(geneCount)]["Accumulation"] = 0.0;
                }
            }
        }
    }
    return individual;
}

nlohmann::json constructIndividualExtJson()
{
    nlohmann::json individual;
    for (int i = 0; i < getChromosomeCount(); ++i)
    {
        for (int j = 0; j < getGeneCount(); ++j)
        {
            for (int k = 0; k < getBaseCount(); ++k)
            {
                switch (i)
                {
                    case 0:
                        switch (j)
                        {
                            case 0:
                                individual["Switch Chromosome"]["Red Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["Red Gene"]["Activated"] = false;
                                break;
                            case 1:
                                individual["Switch Chromosome"]["Green Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["Green Gene"]["Activated"] = false;
                                break;
                            case 2:
                                individual["Switch Chromosome"]["Blue Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["Blue Gene"]["Activated"] = false;
                                break;
                            case 3:
                                individual["Switch Chromosome"]["X Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["X Gene"]["Activated"] = false;
                                break;
                            case 4:
                                individual["Switch Chromosome"]["Y Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["Y Gene"]["Activated"] = false;
                                break;
                            case 5:
                                individual["Switch Chromosome"]["Z Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["Z Gene"]["Activated"] = false;
                                break;
                            case 6:
                                individual["Switch Chromosome"]["RotateSpeed Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["RotateSpeed Gene"]["Activated"] = false;
                                break;
                            case 7:
                                individual["Switch Chromosome"]["PlaneCount Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Switch Chromosome"]["PlaneCount Gene"]["Activated"] = false;
                                break;
                        }
                        break;
                    case 1:
                        switch (j)
                        {
                            case 0:
                                individual["Expression Chromosome"]["Red Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["Red Gene"]["Accumulation"] = 0;
                                break;
                            case 1:
                                individual["Expression Chromosome"]["Green Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["Green Gene"]["Accumulation"] = 0;
                                break;
                            case 2:
                                individual["Expression Chromosome"]["Blue Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["Blue Gene"]["Accumulation"] = 0;
                                break;
                            case 3:
                                individual["Expression Chromosome"]["X Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["X Gene"]["Accumulation"] = 0;
                                break;
                            case 4:
                                individual["Expression Chromosome"]["Y Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["Y Gene"]["Accumulation"] = 0;
                                break;
                            case 5:
                                individual["Expression Chromosome"]["Z Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["Z Gene"]["Accumulation"] = 0;
                                break;
                            case 6:
                                individual["Expression Chromosome"]["RotateSpeed Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["RotateSpeed Gene"]["Accumulation"] = 0;
                                break;
                            case 7:
                                individual["Expression Chromosome"]["PlaneCount Gene"]["base" + std::to_string(k)] = createBase();
                                individual["Expression Chromosome"]["PlaneCount Gene"]["Accumulation"] = 0;
                                break;
                        }
                        break;
                }
            }
        }
    }
    return individual;
}

nlohmann::json constructPopulationJson()
{
    nlohmann::json population;
    for (int pop = 0; pop < getGenerationSize(); ++pop)
    {
        for (int i = 0; i < getChromosomeCount(); ++i)
        {
            for (int j = 0; j < getGeneCount(); ++j)
            {
                for (int k = 0; k < getBaseCount(); ++k)
                {
                    population["individual" + std::to_string(pop)]["chromosome" + std::to_string(i)]["gene" + std::to_string(j)]["base" + std::to_string(k)] = createBase();
                }
            }

        }
    }
    return population;
}