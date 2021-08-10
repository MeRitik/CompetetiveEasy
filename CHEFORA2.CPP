#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(ind,s, range) for(int ind = s; ind <= range; ind++)
#define pb emplace_back
#define ppb pop_back
#define MX 100005

ll binpow(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int i;
    vector<ll> chef;
    chef.emplace_back(0);
    loop1(i,1,MX)
    {
        ll chf = i,num = i / 10;

        while(num){
            chf = chf*10 + num%10;
            num /= 10;
        }
        chef.pb(chf);
    }

    /*for(auto it:chef) {
        cout << it << ' ';
    }*/

    vector<ll> csum;
    csum.pb(0);
    ll sz = chef.size();
    // , sum = 0;
    loop1(i, 1, sz-1){
        // sum += chef[i];
        csum.pb(chef[i] + csum[i-1]);
    }

    //for(auto it:csum)cout << it << ' ';

    ll T;
    cin>>T;
    while(T--){
        ll l,r;
        cin>>l>>r;
        cout << binpow(chef[l], csum[r] - csum[l], mod) << endl; 
    }

    return 0;
}