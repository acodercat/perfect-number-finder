#include "PerfectNumber.h"

// Function to check if a given number is perfect
bool isPerfect(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; i++) {
        // Check if i is a divisor of number
        if (number % i == 0) {
            // If i is a divisor, add it to sum
            sum += i;
        }
    }
    return sum == number;
}