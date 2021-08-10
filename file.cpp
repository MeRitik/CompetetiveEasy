#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'

int setBits(int N) {
        // Write Your Code here
        int ans = 0;
        while(N){
            ans += (N&1);
            N >>= 1;
        }
        return ans;
    }

int countSetBits(int n)
{
    // Your logic here
    int count = 0;
    for(int i = 1; i <= n; i++){
        
        int x = i;
        while(x){
            count += (x&1);
            x >> 1;
        }
    }
    return count;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    /*int a,b;
    cin>>a>>b;
    ll ans = 0;

    for(ll i = a; i < b; i++){
        for(ll j = i; j < b; j++){
            ans = max(ans, (i^j));        }
    }

    cout << ans << endl;
    */

    //cout << setBits(6) << endl;
    cout << countSetBits(4) << endl;

   /* int cnt = 0;
    for(int i = 1; i <= 17; i++){
        cnt += setBits(i);
    }
    cout << cnt;*/
    

    return 0;
}