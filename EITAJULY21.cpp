#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;
    cin>>T;
    while(T--){
    	int d, x, y, z;
    	cin>>d>>x>>y>>z;

    	int first = 7*x;
    	int second = y*d + z*(7-d);
    	cout << max(first, second) << endl;
	}
    
    

    return 0;
}