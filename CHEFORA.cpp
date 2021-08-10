#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define N 100001

ll ModExp(ll x, unsigned int y)
{
	ll res = 1;
	x = x%mod;

	if(x==0)return 0;
	while(y>0){
		if(y&1){
			res = (res*x) % mod;
		}
		y = y>>1;
		x = (x*x) % mod;
	}

	return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;
    cin>>T;

    std::vector<ll> v(N);
    v[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
    	ll num1 = i, num2 = i;
    	num1/=10;
    	while(num1){
    		num2 = (num2*10) + (num1%10);
    		num1 /= 10;
    	}
    	v[i] = num2+v[i-1];
    	//cout << v[i] << endl;
    }

    while(T--){
    	int l,r;
    	cin>>l>>r;

    	ll res = 1, ps = v[l] - v[l-1], p = v[r] - v[l];

    	cout << ModExp(ps, p) << endl;
    }

    return 0;
}