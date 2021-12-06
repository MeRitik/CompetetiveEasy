#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl '\n'

void GenerateSubsets(string str, string temp, int ind)
{
	int len = str.length();
	if(ind == len){
		cout << temp << endl;
		return;
	}

	//Adding element on ind position to temp string 
	temp.push_back(str[ind]);
	GenerateSubsets(str, temp, ind+1);

	//Backtracking
	temp.pop_back();
	GenerateSubsets(str, temp, ind+1);

}


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
      	string str2 = "";
      	GenerateSubsets(str, str2, 0);
    }

    
    

    return 0;
}