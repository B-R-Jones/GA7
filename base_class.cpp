#include <iostream>
#include "creators.h"
#include "simSettings.h"
#include "expression.h"


class base {
    //int value;
    //double score{ 0.0 };
public:
    int value;
    double score{ 0.0 };

    base()
    {
        value = createBase(); 
        set_score();
    };

    double get_score() 
    { 
        return score; 
    };

    void set_score() 
    { 
        score = expressionValue(value); 
    };
};