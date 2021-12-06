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

vector<int> MaxInWindow(vector<int> v, int k) {
    int  n = v.size();
    vector<int> ans;
    deque<int> deq;
    if(n == 0)return ans;

    for(int i = 0; i < n; i++) {
        //Remove indexes which are not in range
        if(!deq.empty() and deq.front() == i-k)deq.pop_front();

        //Remove smaller elements
        while(!deq.empty() and v[deq.back()] < v[i])
            deq.ppb();

        deq.pb(i);
        if(i>=k-1)ans.pb(v[deq.front()]);
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif
    
    srand(time(NULL));
    int T;
    cin>>T;
    while(T--) {
    
    int n, k;
    cin>>n>>k;
    vector<int> v(n);

    loop(i, n)cin>>v[i];
    vector<int> ans = MaxInWindow(v, k);


    
    
    
    for(auto it: ans) {
        cout << it << ' ';
    }cout << endl;
}
    return 0;
}