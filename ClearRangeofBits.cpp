#include <bits/stdc++.h>
using namespace std;

int ClearLastNBits(int num, int N)
{
    //N no of bits will be cleared
    int mask = ((-1) << N);
    return (num & mask);
}

int ClearRangeofBits(int n, int i, int j)
{
    int allOne = -1;
    int left = (allOne<<(j+1));
    int right = (1<<i)-1;
    int mask = left|right;
    return (n&mask);
}

int main()
{
    //1(0 0 0)1 0
    //1 0 1 0 1 0
    int n = 127;
    //int N = 3;
    //cout << ClearLastNBits(n, N) << endl;
    cout << ClearRangeofBits(127,2,3) << endl;
    return 0;
}