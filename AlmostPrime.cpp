#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'

int SieveOfEratosthenes(int n)
{
	int pr[n+1] = {};
	vector<int> primes;
	int i, j;

	for(int i = 2; i <= n; i++){
		if(!pr[i]) {
			primes.push_back(i);
			for(j = i; j <= n; j += i){
				pr[j]++;
			}
		}
	}

	int ans = 0;
	for(i = 2; i <= n; i++){
		if(pr[i] == 2)ans++;
	}
	return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int n;
    cin>>n;

    cout << SieveOfEratosthenes(n) << endl;

    
    

    return 0;
}