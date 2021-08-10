#include <iostream>
#include <bitset>
#include <vector>
#include <limits.h>
using namespace std;
#define ll long long int

const ll n = 10000000;
bitset<10000005> b;
vector<ll> primes;

void iritik(){
	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
	#endif
}

void sieve(){

	//Set all the bits
	b.set(); // 1, 1, 1, 1, ........

	b[0] = b[1] = 0;

	for(ll i = 2; i <= n; i++){

		if(b[i] == 1){
			primes.push_back(i);
			for(ll j = i*i; j <= n; j +=i){
				b[j] = 0;
			}
		}
	}
}

bool isPrime(ll no){
	if(no<=n){
		return b[no] == 1 ? true : false;
	}

	for(ll i = 0; primes[i]*primes[i] <= no; i++){
		if(no % primes[i] == 0)return false;

	}

	return true;
}

int main(){
	iritik();
	sieve();

	ll num;
	cin>>num;

	if(isPrime(num)){
		cout << "It is Prime" << endl;
	}
	else{
		cout << "NOt PRime" << endl;
	}



	return 0;
}
