/*******************************************************************************
 * Name          : rpmult.cpp
 * Author        : Dakshin Kannaan
 * Version       : 1.0
 * Date          : 11/12/2021
 * Description   : Performs Russian Peasant Multiplication.
 * Pledge        : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

unsigned long russian_peasant_multiplication(unsigned int m, unsigned int n) {
	unsigned long m_long = m;
	unsigned long result = 0;
	if(n > m_long)
	{
		unsigned long temp = n;
		n = m_long;
		m_long = temp;
	}
	    while (n > 0)
	    {
	        if (n & 1)
	            result = result + m_long;
	        m_long = m_long << 1;
	        n = n >> 1;
	    }
	    return result;
}

int main(int argc, char* const argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer m> <integer n>" << endl;
        return 1;
    }

    int m, n;
    istringstream iss;

    iss.str(argv[1]);
    if ( !(iss >> m) || m < 0 ) {
        cerr << "Error: The first argument is not a valid nonnegative integer."
             << endl;
        return 1;
    }

    iss.clear();
    iss.str(argv[2]);
    if ( !(iss >> n) || n < 0 ) {
        cerr << "Error: The second argument is not a valid nonnegative integer."
             << endl;
        return 1;
    }

    // TODO - produce output
    cout << m << " x " << n << " = " << russian_peasant_multiplication(m,n) << endl;
    return 0;
}
