#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
const int HIGH = 100;

vector<bool> v(HIGH, true);
void Sieve()
{
    v[0] = v[1] = false;
    for (int i = 2; i * i < HIGH; i++)
    {
        for (int j = i * i; j < HIGH; j += i)
        {
            v[j] = false;
        }
    }
}

int main()
{
    string PATH = "PrimeNumbers.txt";
    fstream file;
    file.open(PATH, ios::app);
    Sieve();

    for (int i = 0; i < HIGH; i++)
    {
        if (v[i] == true)
        {
            file << i << ' ';
        }
    }

    return 0;
}