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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    int n, p;
    cin >> n;
    vector<int>v;
    v.pb(0);


    for (int i = 0; i < n; i++)
    {
        cin >> p;
        v.pb(p + (v[i]));
    }

    int tc, r, l; cin >> tc;
    while (tc--) {
        cin >> l >> r;
        cout << v[r + 1] - v[l] << endl;
    }


    return 0;
}