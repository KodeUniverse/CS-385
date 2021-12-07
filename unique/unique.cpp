/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Dakshin Kannaan
 * Date        : 10/15/2021
 * Description : Finding uniqueness of chars with bitmap.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>

using namespace std;

bool is_all_lowercase(const string& s)
{
    for (const char& i : s) 
    {
    	if ( i > 'z' || i < 'a' ) return false;
    }
    return true;
}

bool all_unique_letters(const string& s)
{
    unsigned int bitset = 0; //bitmap for representing each unique letter
    for (const char& i : s)
    {
        //mapping the 26 letters of alphabet, a = 0, b = 1, ... z = 25
        //in binary, a = 0001, b = 0010, c = 0100 and so on
        unsigned int n = i - 'a';
        if ((bitset & (1 << n)) > 0) //if the nth bit of bitset == 1, then it is duplicate. so if (1 << n) > 0 , nth bit is duplicate.
        {
            return false;
        }
        bitset |= (1 << n); //using OR to set the seen letters to the bitmap
    }
    return true;
}

int main(int argc, char* const argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <string>" << "\n";
        return 1;
    }
    istringstream iss;
    string s;

    iss.str(argv[1]);
    if (!(iss >> s) || !(is_all_lowercase(s)))
    {
        cerr << "Error: String must contain only lowercase letters." << "\n";
        return 1;
    }
    iss.clear();

    if (s.length() > 26 || !all_unique_letters(s))
    {
        cout << "Duplicate letters found." << "\n";
    }
    else
    {
        cout << "All letters are unique." << "\n";
    }

    return 0;
}
