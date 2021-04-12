#pragma once
#include <nlohmann/json.hpp>

nlohmann::json constructGeneJson();
nlohmann::json constructChromosomeJson();
nlohmann::json constructIndividualJson();
nlohmann::json constructIndividualExtJson();
nlohmann::json constructPopulationJson();