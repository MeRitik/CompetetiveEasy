#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>> n;

    int arr[50000] = {0};
    arr[0] = 1;
    int q = 2,num = 0,x = 0,len=1;

    for(int q = 2;q <= n;q++)
    {
        num = 0;
        x = 0;

        while(x < len)
        {
            arr[x] = arr[x] * q;
            arr[x] = arr[x] + num;
            num = arr[x] / 10;
            arr[x] %= 10;
            x++;
        }

        while(num != 0)
        {
            arr[len] = num%10;
            num = num / 10;
            len++;
        }
    }
    len--;
    while(len >= 0)
    {
        cout << arr[len];
        len--;
    }
    return 0;
}
