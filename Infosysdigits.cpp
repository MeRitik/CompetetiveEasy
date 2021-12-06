#include <iostream>
using namespace std;
#define endl '\n'

char lVal(int num)
{
    if (num >= 0 and num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}


bool CheckSameDigit(int num, int base)
{
    char x = lVal(num % base);
    num /= base;
    while (num)
    {
        if (lVal(num % base) != x)
            return false;
        num /= base;
    }

    return true;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {

        int num;
        cin >> num;

        bool flag = true;
        for (int i = 2; i < num; i++)
        {
            if (CheckSameDigit(num, i)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
