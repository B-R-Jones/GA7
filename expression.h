#pragma once
#include <nlohmann/json.hpp>

double expressionValue(int x);
nlohmann::json geneExpression(nlohmann::json& x);
nlohmann::json geneExpressionOld(nlohmann::json& x);
nlohmann::json cyclePass(nlohmann::json& x);
