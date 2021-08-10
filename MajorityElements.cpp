#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'
#define loop(i, range) for(int i = 0; i < range; i++)
#define loop1(i, start, end) for(int i = start; i <= end; i++)
#define pb emplace_back
#define ppb pop_back
#define mp make_pair

int MajorityElement(vector<int> &v) {
	int el = 0,cnt = 0;

	for(int num: v) {
		//cout << num << ' ';
		if(cnt == 0) {
			el = num;
		}

		if(num == el) {
			cnt+=1;
		}
		else{
			cnt-=1;
		}
	}

	return el;
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
       vector<int> vec;
       loop(i,n){
       	   int n;
       	   cin>>n;
       	   vec.pb(n);
       }
       cout << MajorityElement(vec) << endl;
    }
    return 0;
}