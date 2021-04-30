#pragma once
#include <nlohmann/json.hpp>

nlohmann::json constructBaseJson(int x, int z = getBaseCount());
nlohmann::json constructGeneJson(int x = 0);
nlohmann::json constructChromosomeJson(int x = -1);
nlohmann::json constructIndividualJson(int x = 0);
nlohmann::json constructPopulationJson();