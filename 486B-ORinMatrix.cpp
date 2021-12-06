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

void main2()
{
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    int arr[n][m];
    int hashArr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            hashArr[i][j] = arr[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {

                for (int x = 0; x < n; x++)
                    hashArr[x][j] = 0; //
                for (int y = 0; y < m; y++)
                    hashArr[i][y] = 0;
            }
        }
    }



    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int tmp = 0;
            for (int x = 0; x < n; x++)
                tmp |= hashArr[x][j];

            for (int y = 0; y < m; y++)
                tmp |= hashArr[i][y];

            if (arr[i][j] != tmp)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << hashArr[i][j] << ' ';
    

    return 0;
}