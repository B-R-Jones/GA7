#include <iostream>

int setVariable()
{
    std::cout << "Enter integer variable value: ";
    int testSet{};
    std::cin >> testSet;

    return testSet;
}