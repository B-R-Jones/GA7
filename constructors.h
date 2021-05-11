#pragma once
#include <nlohmann/json.hpp>
#include "simSettings.h"

using nlohmann::json;
nlohmann::json constructBaseJson(int x = 0, int z = getBaseCount());
nlohmann::json constructGeneJson(int x = 0);
nlohmann::json constructChromosomeJson(int x = -1);
nlohmann::json constructIndividualJson(int x = 0);
nlohmann::json constructPopulationJson();
nlohmann::json constructCycleJson(nlohmann::json& x, int y = 0);
nlohmann::json runCycles(nlohmann::json& x);
void runGenCycles(nlohmann::json& x, nlohmann::json& y);