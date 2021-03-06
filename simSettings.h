#pragma once
#include <chrono>

// Creation management methods below; each can be called individually
// Set options should be an advanced option only
int getBaseCount();
bool setBaseCount(unsigned char x);
int getGeneCount();
int getGeneLength();
bool setGeneCount(unsigned char x);
int getChromosomeCount();
int getChromosomeLength();
bool setChromosomeCount(unsigned char x);
int getChromLoc();
void resetChromLoc();
int checkChromLoc();
void updateChromLoc();
void setChromLoc(int x);
int getStrandLength();
int getGenerationCount();
int getGenerationSize();
int getCycleCount();


// Time management methods below; these do not have manual set options
// These are not planned to be accessible through any option menu
std::chrono::milliseconds getStamp1();
std::chrono::milliseconds getStart();
std::chrono::milliseconds getEnd();
int runTime();
void setTime();

// Mutation management methods below: manual set options may be planned
// Set options should be an advanced option only
double getMutationRate();
bool setMutationRate(unsigned char x);

// Target management methods below; no manual set options
std::string getTargetStrand();