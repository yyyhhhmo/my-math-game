// random.h
#ifndef YAHIA_RANDOM_H
#define YAHIA_RANDOM_H

#include <vector>
#include <fstream>  // Add this for file operations
#include <iostream> // Add this for cout

// Math operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Score management functions
void saveScore(int score);
std::vector<int> loadScores();
void displayScoreHistory();
std::vector<double> keep_results(int score);

#endif
