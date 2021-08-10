#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair
bitset<32> bits;

int FlippedBits(long long n)
{
	bits = n;
	//bits.flip();
	cout << bits << endl;
	//return ~(bits.to_ulong());
	return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;
    cin>>T;
    while(T--) {
       
    	long long num;
    	cin>>num;

    	cout << FlippedBits(num) << endl;
    }

    
    

    return 0;
}