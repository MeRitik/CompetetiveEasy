#include<iostream>
#include<unordered_map>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    unordered_map<string, int> umap;

    string str;
    int T;
    cin>>T;
    while(T--) {
        cin>>str;

        if(umap[str] == 0){
            umap[str]++;
            cout << "OK" << endl;
        }
        else{
            cout << str << umap[str] << endl;
            umap[str]++;
        }
    }

    return 0;
}