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
#include "base_class.cpp"



int main()
{
    //std::cout << "GA7 Simulation v0.0\n";
    //std::cout << "Setting random seed via time differential...\n";
    //setTime();
    //std::cout << "Generic Integrity Tests:\n";
    //nlohmann::json test_dump;
    //for (int i = 0; i < 4; i++)
    //{
    //    switch (i)
    //    {
    //    case 0:
    //        test_dump = constructBaseJson(0);
    //        break;
    //    case 1:
    //        test_dump = constructGeneJson();
    //        break;
    //    case 2:
    //        test_dump = constructChromosomeJson();
    //        break;
    //    case 3:
    //        test_dump = constructIndividualJson();
    //        break;
    //    }
    //    std::cout << "\nDumping test...\n" << test_dump.dump();
    //}
    //std::cout << "Creating base population test file...\n";
    //nlohmann::json test(constructPopulationJson());
    //std::ofstream testFeed("population.json");
    //testFeed << std::setw(4) << test << std::endl;

    //std::cout << "Expression test...\n";
    //nlohmann::json ind(constructIndividualJson());
    //geneExpression(ind);

    //std::ofstream indFeed("individual_expression_test.json");
    //indFeed << std::setw(4) << test << std::endl;



    base b;
    std::cout << std::to_string(b.get_score()) << "\n";
    b.set_score();
    std::cout << std::to_string(b.get_score()) << "\n";
}

