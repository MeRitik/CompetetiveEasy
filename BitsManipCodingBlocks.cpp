#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n)
{
    return (n&1);
}

bool GetBit(int n, int pos)
{
    int mask = (1<<pos);
    return (n&mask)>0?true:false;
}

int setBit(int n, int pos)
{
    int mask = (1<<pos);
    return (n|mask);
}

int clearBit(int n, int pos)
{
    int mask = ~(1<<pos);
    return (mask&n);
}

int UpdateBit(int n, int pos, int bit)
{
    int x = clearBit(n,pos);
    int mask = (bit<<pos);
    return (x|mask);
}

//1 1 0 0
//1 1 1 0


int main()
{
    //1 0 0 1 0 0 0
    int n = 72;
    //cout << isOdd(n) << endl;
    //cout << GetBit(n, 3) << endl;
    //cout << setBit(n,1) << endl;
    //cout << clearBit(n, 2) << endl;
    //cout << UpdateBit(n,5,1) << endl;

    return 0;
}