#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>
#include "creators.h"
#include "simSettings.h"
#include "mutators.h"
#include "parsers.h"
#include "constructors.h"
#include "expression.h"


int main()
{
    std::cout << "GA7 Simulation v0.0\n";
    std::cout << "Setting random seed via time differential...\n";
    setTime();
 
    std::cout << "Mutation rate currently set to: " << getMutationRate() << "% \n";

    std::cout << "Mutation rate now set to: " << getMutationRate() << "% \n";
    std::cout << "Generic individual integrity creation test: " << createIndividual() << "\n";

    nlohmann::json pop;
    for (int popCount = 0; popCount < getGenerationSize(); popCount++)
    {
        pop["cycle0"]["individual" + std::to_string(popCount)] = constructIndividualJson();
    }
    std::ofstream popStart("popStart.json");
    popStart << std::setw(4) << pop << std::endl;

    cyclePass(pop);

    std::ofstream popEnd("popEnd.json");
    popEnd << std::setw(4) << pop << std::endl;

    std::ofstream n("individualTest.json");
    nlohmann::json j(constructIndividualJson());
    nlohmann::json output(cyclePass(j));
    n << std::setw(4) << output << std::endl;
}

