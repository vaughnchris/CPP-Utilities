#include "StackOfInts.h"
#include <iostream>

int Utilities::Containers::StackOfInts::Sum()
{
    int sum = 0;
    for (int i = 0; i < this->count; i++)
    {
		sum += (*this)[i];
	}
	return sum;
}

int Utilities::Containers::StackOfInts::Max()
{
    int max = (*this)[0];
    for (int i = 1; i < this->Count(); i++)
    {
        if ((*this)[i] > max)
        {
			max = (*this)[i];
		}
    }
    return max;
}

int Utilities::Containers::StackOfInts::Min()
{
    int min = (*this)[0];
    for (int i = 1; i < this->Count(); i++)
    {
        if ((*this)[i] < min)
        {
            min = (*this)[i];
        }
    }
    return min;
}

int Utilities::Containers::StackOfInts::Average()
{
    int sum = this->Sum();
    return sum / this->Count();
}

int Utilities::Containers::StackOfInts::Mode()
{
    int maxFrequency = 0; // Maximum frequency
    int mode = 0; // Mode value

    // Count the frequency of each element
    for (int i = 0; i < this->Count(); i++) {
        if ((*this)[i] > maxFrequency) {
            maxFrequency = (*this)[i];
            mode = i;
        }
    }
    return mode;
}

int Utilities::Containers::StackOfInts::Range(const int min)
{
   return Max() - Min();
 }

int Utilities::Containers::StackOfInts::Variance()
{
    int n = this->count;
    if (n <= 1) {
        // Not enough data points for variance calculation
        return 0.0;
    }

    // Calculate the mean
    double sum = 0.0;
    for (int i = 0; i < this->count; i++) {
        sum += (*this)[i];
    }
    double mean = sum / n;

    // Calculate the variance
    double variance = 0.0;
    for (int i = 0; i < this->count; i++) {
        double diff = (*this)[i] - mean;
        variance += diff * diff;
    }
    variance /= (n - 1); // Unbiased sample variance

    return variance;
}

int Utilities::Containers::StackOfInts::StandardDeviation()
{
    double sum = 0.0, mean, standardDeviation = 0.0;
    int size = this->count;

    // Calculate the sum of all elements
    for (int i = 0; i < size; ++i) {
        sum += (*this)[i];
    }

    // Calculate the mean (average)
    mean = sum / size;

    // Calculate the sum of squared differences from the mean
    for (int i = 0; i < size; ++i) {
        standardDeviation += pow((*this)[i] - mean, 2);
    }

    // Calculate the standard deviation
    return sqrt(standardDeviation / size);
}

std::string Utilities::Containers::StackOfInts::ToString()
{
    //return a string representation of the stack of integers
    //and all of the statistics
    std::string strOut = "";
    for (int i = 0; i < this->count; i++)
    {
		strOut += std::to_string((*this)[i]) + ", ";
	}
    strOut += "\n";
    strOut += "Sum: " + std::to_string(Sum()) + "\n";
    strOut += "Max: " + std::to_string(Max()) + "\n";
    strOut += "Min: " + std::to_string(Min()) + "\n";
    strOut += "Average: " + std::to_string(Average()) + "\n";
    strOut += "Mode: " + std::to_string(Mode()) + "\n";
    strOut += "Variance: " + std::to_string(Variance()) + "\n";
    strOut += "Standard Deviation: " + std::to_string(StandardDeviation()) + "\n";
    return strOut;
}

void Utilities::Containers::StackOfInts::Print()
{
    	std::cout << ToString();
}
