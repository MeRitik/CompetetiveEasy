#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 101
int arr[N][N], I[N][N];

void printMat(int arr[][N], int dim)
{
    for (int i = 1; i <= dim; ++i)
    {
        for (int j = 1; j <= dim; ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void Mul(int arr[][N], int B[][N], int dim)
{
    int res[dim+1][dim+1];
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            res[i][j] = 0;
            for(int k = 1; k <= dim; k++)
            {
                res[i][j] += (arr[i][k] * B[k][j])%mod;
            }
        }
    }

    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            arr[i][j] = res[i][j];
        }
    }

}

void MatExp(int arr[][N], int dim, int n)
{
    //Creating an Identity matrix
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++)
        {
            if(i==j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    // for(int i = 1; i <= n; i++)
    //     Mul(I, arr, dim);

    while(n){
        if(n&1){
            Mul(I, arr, dim);
            n--;
        }
        else{
            Mul(arr, arr, dim);
            n>>=1;
        }

    }

    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= dim; j++){
            arr[i][j] = I[i][j];
        }
    }

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("checker.in", "w", stdout);
    #endif

    //(dim*dim)^n
    int T, dim, n;
    cin>>T;
    while(T--){
        cin>>dim>>n;

        //Input of the array/Matrix
        for(int i = 1; i <= dim; i++){
            for(int j = 1; j <= dim; j++){
                cin>>arr[i][j];
            }
        }

        MatExp(arr, dim, n);
        printMat(arr, dim);
    }

    return 0;
}
