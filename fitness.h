#pragma once
#include <nlohmann/json.hpp>

void fitnessEval(nlohmann::json& x);
std::string getIndividualStrand(nlohmann::json x);
void findFittest(nlohmann::json x, nlohmann::json& y, nlohmann::json& z);