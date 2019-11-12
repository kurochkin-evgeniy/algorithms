#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert> 

unsigned SumOfÑonsecutiveNumbers(unsigned n)
{
    return n  * (n + 1) / 2;
}


unsigned SumOfNumbers(const std::vector<unsigned>& array)
{
    unsigned sum = 0;
    return std::accumulate(std::begin(array), std::end(array), sum);
}


std::pair<unsigned, unsigned> FindMissingNumbers(const std::vector<unsigned>& array)
{
    auto n = array.size() + 1;
    assert(n > 1);

    unsigned sumOfMisingNumbers = SumOfÑonsecutiveNumbers(n) - SumOfNumbers(array);
    unsigned average = sumOfMisingNumbers / 2;

    unsigned sumOfNumbersSmallerThanAverage = 0;
    for (auto value : array) 
    {
        if (value <= average)
            sumOfNumbersSmallerThanAverage += value;
    }

    unsigned firstNumber  = SumOfÑonsecutiveNumbers(average) - sumOfNumbersSmallerThanAverage;
    unsigned secondNumber = sumOfMisingNumbers - firstNumber;

    return {firstNumber, secondNumber};
}


int main()
{    
    std::vector<unsigned> testArray = { 0}; // 9 and 10 are missing
 
    std::random_shuffle(std::begin(testArray), std::end(testArray));  // shuffle numbers automatically

    auto numbers = FindMissingNumbers(testArray);
    std::cout << "Numbers are " << numbers.first << " and " << numbers.second << std::endl;

    return 0;
}
