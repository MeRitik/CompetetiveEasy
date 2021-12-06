#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    int q, a, b, c, ans = 0;
    cin >> q;
    while (q--) {
        cin >> a >> b >> c;
        ans += (a + b + c);
    }
    if (ans == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}