#include <queue>
#include <set>
#include <unordered_set>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair

int KnapSack(int weights[], int values[], int Capacity, int size)
{
    if (Capacity == 0 || size == 0)
        return 0;

    if (weights[size - 1] <= Capacity)
    {
        return max(values[size - 1] + KnapSack(weights, values, Capacity - weights[size - 1], size - 1),
                   KnapSack(weights, values, Capacity, size - 1));
    }
    else if (weights[size - 1] > Capacity)
    {
        return KnapSack(weights, values, Capacity, size - 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    int weights[6] = {1, 3, 5, 7, 9};
    int values[6] = {2, 4, 6, 22, 5};
    int Capacity = 15;
    int size = sizeof(weights)/sizeof(int);

    cout << KnapSack(weights, values, Capacity, size) << endl;



    return 0;
}