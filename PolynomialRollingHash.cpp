#include<iostream>
#include<string>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair

ll PolyRollHash(string str){
	int hash = 0;
	int p = 1;
	//change prime according to character set
	int prime = 31;

	for(char ch: str) {
		hash = (hash + (ch - 'a' + 1) * p) % mod;
		p = (p * prime) % mod;
	}

	return hash;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    string str;
    cin>>str;

    if(str == ".") {
    	cout << "Invalid!" << endl;
    }else{
    	cout << "Hash Value of " + str + " is: " << PolyRollHash(str) << endl;
    }

    



    return 0;
}