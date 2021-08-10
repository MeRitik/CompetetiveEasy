#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;
    cin>>T;
    string str;


    while(T--) {
        int ctr = 0;
        cin>>str;
        // cout << str <<endl;

        for(int i = 0; i < str.length(); i++){
            if(str[i] == '1'){
                ctr++;
                while(str[i] != '0' and i<str.length()){
                    i++;
                }
            }
        }

        if(ctr == 1)
                cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }



    return 0;
}