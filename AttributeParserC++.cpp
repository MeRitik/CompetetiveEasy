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
#include <sstream>
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

    int n, k;
    cin >> n >> k;

    cin.ignore();
    vector<string> code, query;

    string temp;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        code.pb(temp);
    }

    for (int i = 0; i < k; i++)
    {
        getline(cin, temp);
        query.pb(temp);
    }


    map<string, string> mp;
    vector<string> tags;

    for (int i = 0; i < n; i++)
    {
        temp = code[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        // if it is a closing tag
        if (temp.substr(0, 2) == "</")
        {
            tags.pop_back();
        }
        else {
            stringstream obj;
            obj.str("");
            obj << temp;
            // cout << temp << ' ';

            string a, b, c;
            char ch;
            obj >> ch >> a >> b >> ch >> c;

            string temp1 = "";

            if (tags.size() > 0)
            {
                // last vector word
                temp1 = *tags.rbegin();
                temp1 += "." + a;
            }
            else {
                temp1 = a;
            }

            tags.pb(temp1);

            mp[*tags.rbegin() + "~" + b] = c;

            while (obj)
            {
                obj >> b >> ch >> c;
                mp[*tags.rbegin() + "~" + b] = c;
            }
        }
    }


    // for (int i = 0; i < k; i++)
    // {
    //     if (mp.find(query[i]) == mp.end())
    //         cout << "Not Found!" << endl;
    //     else
    //         cout << mp[query[i]] << endl;
    // }


    for (auto it : mp)
        cout << it.first << ' ' << it.second << endl;

    return 0;
}











// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value