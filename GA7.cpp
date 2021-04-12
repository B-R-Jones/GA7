#include <iostream>
#include <string>
#include "creators.h"
#include "simSettings.h"
#include "mutators.h"
#include "parsers.h"
#include "constructors.h"
#include <nlohmann/json.hpp>
#include <iomanip>
#include <fstream>

int main()
{
    std::cout << "GA7 Simulation v0.0\n";
    std::cout << "Setting random seed via time differential...\n";
    setTime();
 
    std::cout << "Mutation rate currently set to: " << getMutationRate() << "% \n";

    std::cout << "Mutation rate now set to: " << getMutationRate() << "% \n";
    std::cout << "Generic individual integrity creation test: " << createIndividual() << "\n";

    // The below has been sent to constructors.cpp to build the json object
    //std::string gene{"{\n"};
    //std::string count{};
    ////char count{};
    //for (int i = 0; i < getBaseCount(); ++i)
    //{
    //    //count = static_cast<char>(getBaseCount());
    //    //count = static_cast<char>(i);
    //    count = std::to_string(i);
    //    std::string newBase{ std::to_string((createBase())) };
    //    if (i < getBaseCount()-1)
    //    {
    //        gene += "\"base" + count + "\" : " + newBase + ",\n";
    //    }
    //    else
    //    {
    //        gene += "\"base" + count + "\" : " + newBase + "\n";
    //    }
    //    
    //    
    //}
    //gene += "}";
    //std::cout << gene << "\n";

    ////const char* arrGene;
    ////arrGene = &gene[0];
    //nlohmann::json jsonGene(constructJson(&gene[0]));

    std::ofstream l("geneTest.json");
    l << std::setw(4) << constructGeneJson() << std::endl;

    std::ofstream m("chromosomeTest.json");
    m << std::setw(4) << constructChromosomeJson() << std::endl;

    std::ofstream n("individualTest.json");
    n << std::setw(4) << constructIndividualJson() << std::endl;

    std::ofstream o("individualExtTest.json");
    o << std::setw(4) << constructIndividualExtJson() << std::endl;

    std::ofstream p("populationTest.json");
    p << std::setw(4) << constructPopulationJson() << std::endl;

    std::cout << 

    //std::ofstream o("geneTest.json");
    //o << std::setw(4) << jsonGene << std::endl;
    
    //char* jsonArr;
    //std::string gene{ createGene() };
    //jsonArr = &gene[0];
    //nlohmann::json jsonObj(constructJson(jsonArr));
    //std::ofstream o("gene.json");
    //o << std::setw(4) << jsonObj << std::endl;

    //std::vector<std::vector<std::vector<std::vector<std::string> > > > testPop;

    
    //for (int i = 0; i < 10; i++)
    //{
    //    std::vector<std::vector<std::vector<std::string> > > parsedStrand = readDNA(createIndividual());
    //    testPop.push_back(parsedStrand);
    //}
    //ouptutPopInfo(testPop);
}

