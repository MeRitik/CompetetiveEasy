#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back

int Operations(vector<int> v) {
	int sz = v.size();
	int i = 0, j = sz-1, count = 0;

	while(i<=j) {
		if(v[i] == v[j]){
			i++;
			j--;
		}
		else if(v[i] < v[j]) {
			i++;
			v[i] = v[i] + v[i-1];
			count++;
		}
		else {
			j--;
			v[j] = v[j] + v[j+1];
			count++;
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

    int T;
    cin>>T;
    while(T--) {
       int n;
       cin>>n;
       vector<int> v(n);
       for(auto &it:v){
       	cin>>it;
       }

       cout << Operations(v) << endl;


    }
    

    
    

    return 0;
}