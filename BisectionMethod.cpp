#include <iostream>
using namespace std;
#define places 1e-5 // 1*10^-5
//X^3 - 3X - 9 = 0


double res(double x){
    //Equation for getting the root
    return (x*x*x - 3*x -9);
}

void bisect(double left, double right){
    //If f(left) * f(right) < 0, then only finding the roots is possible
    if(res(left) * res(right) >= 0.0){
        cout << "Not Possible" << endl;
            return;
    }

    double mid = left;

    //While we get the result accurate to the no of places we want
    while((right - left) >= places){
        mid = (left + right) / 2;

        //if we get the required answer, just break from the loop
        //mid is our answer
        if(res(mid) == 0.0)break;

        //If the result is less than 0
        else if(res(mid) * res(left) > 0)
            left = mid;

        //if the result is greater than 0
        else
            right = mid;
    }

    cout << "The Root of the given equation is " << mid << endl;
}

int main()
{
    //Range between which the roots can be found
    double a,b;
    cin>>a>>b;
    bisect(a, b);



    return 0;
}
