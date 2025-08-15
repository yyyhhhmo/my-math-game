// random_add.cpp (implementation file)
#include "random.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

// Math function implementations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }
}

// Save score to file
void saveScore(int score) {
    std::ofstream file("scores.txt", std::ios::app);  // Append mode
    if (file.is_open()) {
        file << score << std::endl;
        file.close();
        std::cout << "Score saved!" << std::endl;
    } else {
        std::cout << "Error: Could not save score to file." << std::endl;
    }
}

// Load and return all previous scores
std::vector<int> loadScores() {
    std::vector<int> scores;
    std::ifstream file("scores.txt");
    int score;
    
    if (file.is_open()) {
        while (file >> score) {
            scores.push_back(score);
        }
        file.close();
    }
    
    return scores;
}

// Display score history
void displayScoreHistory() {
    std::vector<int> scores = loadScores();
    
    if (scores.empty()) {
        std::cout << "No previous scores found." << std::endl;
        return;
    }
    
    std::cout << "\n--- Score History ---" << std::endl;
    for (size_t i = 0; i < scores.size(); ++i) {
        std::cout << "Game " << (i + 1) << ": " << scores[i] << std::endl;
    }
    
    // Calculate and show average
    int total = 0;
    for (int score : scores) {
        total += score;
    }
    double average = static_cast<double>(total) / scores.size();
    std::cout << "Average score: " << std::fixed << std::setprecision(1) 
              << average << std::endl;
}

// Updated keep_results function that actually saves
std::vector<double> keep_results(int score) {
    // Save current score to file
    saveScore(score);
    
    // Load and display all scores
    displayScoreHistory();
    
    // Return current score for compatibility
    std::vector<double> currentScore = {static_cast<double>(score)};
    return currentScore;
}