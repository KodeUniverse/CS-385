/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Dakshin Kannaan
 * Date        : September 28, 2021
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>


using namespace std;

class PrimesSieve
{
   public:
    PrimesSieve(int limit);

    ~PrimesSieve()
    {
        delete[] is_prime_;
    }

    int num_primes() const
    {
        return num_primes_;
    }

    void display_primes() const;

   private:
    // Instance variables
    bool* const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) : is_prime_{new bool[limit + 1]}, limit_{limit}
{
    sieve();
}

void PrimesSieve::display_primes() const
{

    cout << "Number of primes found: " << num_primes() << "\n";
    cout << "Primes up to " << limit_ << ":\n";

    const int max_prime_width = num_digits(max_prime_),
    		  primes_per_row = 80 / (max_prime_width + 1);

    //Alignment handling
    int row_count = 0;
    for (int i = 2; i < limit_ + 1; i++)
    {
        if (row_count == primes_per_row)
        {
            row_count = 0;
            cout << "\n";
        }

        if (is_prime_[i] == false)
        {
            if (row_count != 0)
            {
                cout << " ";
            }

            if (num_primes() > primes_per_row)
            {
                cout << setw(max_prime_width) << i;
            }
            else
            {
                cout << i;
            }
            row_count++;
        }
    }
    cout << "\n";
}

int PrimesSieve::count_num_primes() const
{
    int num = 0;
    for (int i = 2; i < limit_ + 1; i++)
    {
        if (is_prime_[i] == false)
        {
            num++;
        }
    }
    return num;
}

void PrimesSieve::sieve()
{
	//Sieve of Eratosthenes algorithm
    for (int i = 2; i <= sqrt(limit_); i++)
    {
        if (is_prime_[i] == false)
        {
            for (int j = (i*i); j <= limit_; j += i)
            {
                is_prime_[j] = true;
            }
        }
    }

    //Finding the maximum prime
    for (int i = limit_; i > 2; i--)
    {
        if (is_prime_[i] == false)
        {
            max_prime_ = i;
            break;
        }
    }
    num_primes_ = count_num_primes();
}


int PrimesSieve::num_digits(int num)
{
	if (num / 10 == 0)
	{
		return 1;
	}
	else
	{
		return 1 + num_digits(num / 10);
	}
}

int main()
{
    cout << "**************************** "
         << "Sieve of Eratosthenes"
         << " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if (!(iss >> limit))
    {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2)
    {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    cout << "\n";
    PrimesSieve sieve(limit);
    sieve.display_primes();

    return 0;
}
