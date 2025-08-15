#include "random.h"
#include <iostream>
#include <random>

 
int main(){
    int score = 0;
    int rounds = 0;
    while (rounds < 10) {
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> num_dis(1, 100);

std::uniform_int_distribution<> op_dis(1, 4);
double num1 = num_dis(gen);
double num2 = num_dis(gen);
int op = op_dis(gen);

char symbol;
double result; 
double correctresult;

switch(op){
    case 1:
        symbol = '+';
        correctresult = add(num1, num2);
        break;

        case 2:
        symbol = '-';
        correctresult = subtract(num1, num2);
        break;
    case 3:
        symbol = '*';
        correctresult = multiply(num1, num2);
        break;

        case 4:
        symbol = '/';
        if (num2 != 0) {
            correctresult = divide(num1, num2);
        } else {
            continue;
}break;

}
   std::cout << "Solve: " << num1 << symbol <<  num2 << " = ?" << std::endl;
    std::cin >> result;

    if (result == correctresult) {
       std::cout << "Correct!" << std::endl;
        score++;
        rounds++;
    } else {
       std::cout << "Incorrect! The correct answer is: " << correctresult << std::endl;
        rounds++;
        score --;
    }
}
    
   std::cout << "Game Over! Your score is: " << score << std::endl;
   keep_results(score);
    return 0;
}