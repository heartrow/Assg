
#include <iostream>
using namespace std; 

int main()
{
    double weight, height, BMI;
    cout << "This program calculates the Body Mass Index (BMI). \n";
   
    // Ask for user input
    cout << "Enter your body weight (in kg): ";
    cin >> weight;
    cout << "Enter your height (in meters): ";
    cin >> height;

    if (height <= 0) {
         cout << "Height must be greater than zero.\n";
        return 1;  // Exit the program with an error code
    }

    // Calculate BMI
    BMI = weight / (height * height);

    // Output the result
    cout << "Your Body Mass Index (BMI) is = " << BMI << ".\n";
    
    // Provide BMI classification
    if (BMI < 18.5) {
        cout << "You are UNDERWEIGHT. Improve your diet and eating habit.\n";
    } else if (BMI >= 18.5 && BMI < 24.9) {
        cout << "You have a NORMAL WEIGHT. Good job!\n";
    } else if (BMI >= 25 && BMI < 29.9) {
        cout << "You are OVERWEIGHT. Please watch your ";
        cout << "diet and exercise regularly.\n";
    } else {
        cout << "You are OBESE. Please seek medical advices on how";
        cout << " to improve your health condition.\n";
    }

    return 0;
}