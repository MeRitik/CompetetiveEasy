#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string PATH = "PrimeNumbers.txt";
    fstream FILE;
    FILE.open(PATH, ios::in);

    // Read from file
    while (!FILE.eof())
    {
        int a;
        FILE >> a;
        cout << a << ' ';
    }

    return 0;
}