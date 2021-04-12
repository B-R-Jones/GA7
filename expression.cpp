#include <iostream>
#include <string>
#include <sstream>
#include <nlohmann/json.hpp>

double expressionValue(int base)
{
	switch (base)
	{
		case 0:
			return (rand() % 25 + 1) / 100;
		case 1:
			return (rand() % 50 + 26) / 100;
		case 3:
			return (rand() % 75 + 51) / 100;
		case 4:
			return (rand() % 100 + 76) / 100;
	}
}