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
    	string str;
    	cin>>str;
    	ll sum = 0;

    	int l = str.length();
    	for(int i = 0; i < l; i++)
    	{
    		if(isdigit(str[i]) != 0)
    		{
    			sum += (int)(str[i]) - '0';
    		}
    	}
    	cout << sum << endl;
      	
    }

    
    

    return 0;
}