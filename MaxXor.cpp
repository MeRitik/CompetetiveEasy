#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'


int maxXORInRange(int L, int R)
{
    // get xor of limits
    int LXR = L ^ R;
 
    //  loop to get msb position of L^R
    int msbPos = 0;
    while (LXR)
    {
        msbPos++;
        LXR >>= 1;
    }
 
    // construct result by adding 1,
    // msbPos times
    int maxXOR = 0;
    int two = 1;
    while (msbPos--)
    {
        maxXOR += two;
        two <<= 1;
    }
 
    return maxXOR;
}
 

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;cin>>T;
    while(T--){
        int L;cin>>L;
        int R;cin>>R;
        cout << maxXORInRange(R, L) << endl;
    }
    return 0;
}