#include<bits/stdc++.h>
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

    	ll N;
    	cin>>N;

    	ll arr[N], fr[N], bk[N], md[N];
    	for (ll i = 0; i < N; ++i)
    	{
    		cin>>arr[i];
    	}

    	//special case
    	if(N==1){
    		cout << 1 << endl;
    	}
    	else{
    		ll temp = 0;

    		//left gcd
    		for (ll i = 0; i < N; ++i)
    		{
    			fr[i] = temp;
    			if(temp == 0)
    				temp = arr[i];
    			else
    				temp = __gcd(arr[i], temp);
    		}


    		//right gcd
    		temp = 0;
    		for(ll i = N-1; i >= 0; i--)
    		{
    			bk[i] = temp;

    			if(temp	 == 0)
    				temp = arr[i];
    			else
    				temp = __gcd(arr[i], temp);
    		}


    		//storing hcf of left and right in mid
    		for(ll i = 0; i < N; ++i)
    		{
    			if(fr[i] == 0)
    				md[i] = bk[i];
    			else if(bk[i] == 0)
    				md[i] = fr[i];
    			else
    				md[i] = __gcd(bk[i], fr[i]);
    		}

    		//Checking max
    		pair<ll, ll> pr;
    		ll temp2;
    		for(ll i = 0; i < N; ++i)
    		{
    			if(md[i] > pr.first){
    				pr.first = md[i];
    				pr.second = arr[i];
    			}
    			else if(md[i] == pr.first){
    				if(pr.second < arr[i]){
    				pr.second = arr[i];
    			}
    			}
    		}
    		for(ll i = 0; i < N; i++)
    		{
    			if(arr[i] == pr.second && md[i] == pr.first){
    				temp2 = md[i];
    				temp = i;
    			}
    		}

    		arr[temp] = temp2;
			//cout << "First: " << pr.first << " Second: " << pr.second << endl;
    			ll notes = 0;

    			for(ll i = 0; i < N; i++)
    			{
    				/*cout << arr[i] << '/' << pr.first << endl;*/
    				notes += arr[i]/pr.first;
    			}

    			cout << "Notes " << notes << endl;
    		}

    	}
    	


    
    

    return 0;
}