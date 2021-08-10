//Shortesh Route
#include<bits/stdc++.h>
using namespace std;
#define mxm 1e5

int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--){

        int N,M;
        scanf("%d%d", &N,&M);

        int A[N],B[M];
        //Stations
        for(int i = 0; i < N; i++){
            scanf("%d", A[i]);
        }

        //Passengers
        for(int i = 0; i < M; i++){
            scanf("%d", B[i]);
        }

        map<int,int> ch;

        for(int i = 0; i < N; i++){
            if(i == 0)
            {
                ch[i] = 0;
            }
            else if(A[i] != 0)
            {
                ch[i] = 0;
            }
            else
            {
                ch[i] = mxm;
            }
        }

        

        
    }

    return 0;
}