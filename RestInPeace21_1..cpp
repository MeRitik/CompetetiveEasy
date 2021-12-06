#include<iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    int T;cin>>T;
    int num;

    while(T--) {
        cin>>num;
        int num2 = num, flag = 0;


        

        if(num%21 == 0)
            cout << "The streak is broken!" << endl;
        else{
            while(num2>0){
                if(num2%100 == 21){
                    cout << "The streak is broken!" << endl;
                    break;
                }
                num2/=10;
            }
            if(!(num2))
                cout << "The streak lives still in our heart!" << endl;
        }
    }

    return 0;
}