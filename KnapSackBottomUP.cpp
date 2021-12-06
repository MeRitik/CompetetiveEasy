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
#include <cstring>
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
int dp[100][100] = {{0}};

int Knapsack(int wt[], int val[], int n, int W)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    int wt[6] =    {1, 5, 3, 5, 3, 2};
    int val[6] = {6, 14, 8, 13, 5, 2};
    int n = sizeof(val) / 4;
    int W;
    cin >> W;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W; j++)
            if (i == j)
                dp[i][j] = 0;


    cout << Knapsack(wt, val, n, W) << endl;



    return 0;
}