#pragma once
#include <nlohmann/json.hpp>

nlohmann::json propagateGeneration(nlohmann::json x, nlohmann::json y, int z = 0);
nlohmann::json propGenM0(nlohmann::json x, nlohmann::json y);
