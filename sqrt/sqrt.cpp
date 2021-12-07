/*******************************************************************************
 * Name    : sqrt.cpp
 * Author  : Dakshin Kannaan
 * Version : 1.0
 * Date    : September 11, 2021
 * Description : Computes the square root of a double using Newton's method.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <stdlib.h>

double sqrt(double num, double epsilon)
{

	if (num < 0) 
	{
		return std::numeric_limits<double>::quiet_NaN();
	}
	else if (num == 0 || num == 1)
	{
		return num;
	}
	else 
	{
		double last_guess = num;
		double next_guess;
		
		while (true) 
		{
			next_guess = (last_guess + num / last_guess) / 2;
			
			if ((abs(last_guess - next_guess)) <= epsilon)
			{
				break;
			}
			last_guess = next_guess;
		}
		return next_guess;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	std::istringstream iss;
	double num, epsilon;

	if (!(argc > 1 && argc <= 3))
	{
		std::cerr << "Usage: ./sqrt <value> [epsilon]" << "\n";
		return 1;
	}
	else if(argc == 2)
	{
		iss.str(argv[1]);

		if (!(iss >> num))
		{
			std::cerr << "Error: Value argument must be a double." << "\n";
			return 1;
		}
	}
	else
	{
		iss.str(argv[1]);

		if (!(iss >> num))
		{
			std::cerr << "Error: Value argument must be a double." << "\n";
			return 1;
		}
		iss.clear();
		iss.str(argv[2]);

		if (!(iss >> epsilon) || epsilon <= 0)
		{
			std::cerr << "Error: Epsilon argument must be a positive double." << "\n";
			return 1;
		}
	}
	double result = sqrt(num, epsilon);
	std::cout << std::fixed << std::setprecision(8) << result << "\n";
}



