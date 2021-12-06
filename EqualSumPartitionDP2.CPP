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

bool EqualSumPartition(int arr[], int n)
{
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if (sum & 1)
        return false;
    sum = sum / 2 + 1;

    bool dp[n + 1][sum];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }



    return dp[n][sum - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    // Equal Sum Partition
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (EqualSumPartition(arr, n))
        cout << "POSSIBLE" << endl;
    else
        cout << "NOT POSSIBLE" << endl;




    return 0;
}