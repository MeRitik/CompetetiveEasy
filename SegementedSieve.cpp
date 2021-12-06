#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define MAXSIZE 100005
vector<ll> Primes;
bool arr[MAXSIZE];


void SieveOfEratosthenes()
{
	loop(i,MAXSIZE){
		arr[i] = true;
	}

	arr[0] = arr[1] = false;

	//If wrong, check this
	Primes.pb(2);
	for(ll i = 3; i <= MAXSIZE; i+=2){
		if(arr[i] == true){
			Primes.pb(i);
			for(ll j = i*i; j <= MAXSIZE; j+=i){
				arr[j] = false;
			}
		}
	}
}


int main()
{
  #ifndef ONLINE_JUDGE
  freopen("inputf.in", "r", stdin);
  freopen("checker.in", "w", stdout);
  #endif

    SieveOfEratosthenes();

    int T;
    cin>>T;
    while(T--) {
       
    	int n,m;
    	cin>>m>>n;

    	bool SegmentedSieve[n-m+1];
    	loop(i,n-m+1)SegmentedSieve[i] = false;

    	//Segmented Sieve
    	for(auto it : Primes){

    		if(it*it > n)break;
       	
       		ll start = (m / it) * it;

       		if(it>=m and it<=n){
       			start = 2*it;
       		}

       		//Mark all multiples of it
       		for(ll i = start; i<= n; i+=it)
       		{
       			SegmentedSieve[i-m] = true;
       		}
    	}

    	for(int i = m;i<=n;i++)
    	{
    		if(SegmentedSieve[i-m] == 0 and i != 0) {
    			cout << i << ' ';
    		}
    	}
    	cout << "------------------------" << endl;
    }

    return 0;
}
