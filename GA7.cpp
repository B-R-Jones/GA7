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
    std::cout << "Generic Integrity Tests:\n";
    nlohmann::json test_dump;
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            test_dump = constructBaseJson(0);
            break;
        case 1:
            test_dump = constructGeneJson();
            break;
        case 2:
            test_dump = constructChromosomeJson();
            break;
        case 3:
            test_dump = constructIndividualJson();
            break;
        }
        std::cout << "\nDumping test...\n" << test_dump.dump();
    }
    std::cout << "Creating base population test file...\n";
    nlohmann::json test(constructPopulationJson());
    std::ofstream testFeed("population.json");
    testFeed << std::setw(4) << test << std::endl;

    std::cout << "Expression test...\n";
    nlohmann::json ind(constructIndividualJson());
    std::ofstream indFeed("individual_expression_test.json");
    indFeed << std::setw(4) << ind << std::endl;
    
    nlohmann::json pop(constructPopulationJson());
    std::ofstream popFeed("population_expression_test.json");
    popFeed << std::setw(4) << pop << std::endl;

    std::cout << "Cycle pass test...\n";
    nlohmann::json pop4(constructPopulationJson());
    cyclePass(pop4);
    std::ofstream cyclePassFeed1("cycle_pass_test1.json");
    cyclePassFeed1 << std::setw(4) << pop4;
    for (int i = 0; i < 10; ++i)
    {
        cyclePass(pop4);
    }
    std::ofstream cyclePassFeed2("cycle_pass_test2.json");
    cyclePassFeed2 << std::setw(4) << pop4;

    std::cout << "Cycles test...\n";
    nlohmann::json pop2(constructPopulationJson());
    nlohmann::json cyclesPkg(constructCycleJson(pop2));
    std::ofstream cyclesFeed("cycles_test.json");
    cyclesFeed << std::setw(4) << cyclesPkg << std::endl;

    std::cout << "Generation test...\n";
    nlohmann::json pop3(constructPopulationJson());
    nlohmann::json gen(runCycles(pop3));
    std::ofstream genFeed("gen_test.json");
    genFeed << std::setw(4) << gen << std::endl;
}

