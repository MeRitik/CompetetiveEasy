#include <iostream>
using namespace std;
bool dp[101][101];


bool subsetSum(int arr[], int size, int sum)
{
    for (int i = 0; i < size + 1; i++)
        dp[0][i] = false;
    for (int i = 0; i < sum + 1; i++)
        dp[i][0] = true;


    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j]
                           || dp[i - 1][j - arr[i - 1]];
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[size][sum];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    int arr[] = {1, 3, 5, 7};
    int size = sizeof(arr) / sizeof(int);

    int sum = 5;

    cout << subsetSum(arr, size, sum) << endl;

    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }





    return 0;
}