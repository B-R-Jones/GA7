#pragma once
#include <vector>
#include <string>

//std::vector<std::string> readDNA(std::string strand);
std::vector<std::vector<std::vector<std::string>>> readDNA(std::string strand);
void outputStrandInfo(std::vector<std::vector<std::vector<std::string> > > strand);
void ouptutPopInfo(std::vector<std::vector<std::vector<std::vector<std::string> > > > testPop);
//std::vector<std::string> geneVector(std::string gene);