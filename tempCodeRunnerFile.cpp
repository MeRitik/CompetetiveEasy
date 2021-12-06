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
#include <time.h>
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

class Abstract {
public:
    virtual void sayHello(string name) = 0;
};

class Derived: public Abstract {
public:
    void sayHello(string name) {
        cout << "Hello, " << name << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif

    Abstract *bp = new Derived;
    bp->sayHello("Aakash");

    return 0;
}