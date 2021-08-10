#include <iostream>
using namespace std;
#define ll long long int


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;
    cin>>T;
    while(T--){
      	int l,r;
      	cin>>l>>r;
      	ll count = 0;

      	for(int i = l; i <= r; i++)
      	{
      		ll x = i%10;
      		if(x == 2 || x == 3 || x ==9)
      			count++;
      	}

      	cout << count << endl;
    }

    
    

    return 0;
}