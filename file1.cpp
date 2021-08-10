#include<iostream>
#include<vector>
using namespace std;


#include<iostream>
int main() {

	#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("checker.in", "w", stdout);
	#endif
    
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int mask=0;
    for (int i = 0; i < n; i++) {
        mask^=a[i];
    }
    int result=mask;
    int count=0;
    if(!(mask&1)){
        count++;
        mask>>=1;
    }
    mask = 1;
    while(count--){
        mask<<=1;
    }
    
    int num1 =0;
    int num2 = 0;
    for (int i = 0; i < n; i++) {
        if((a[i]&mask)!=0){
            num1^=a[i];
        }
    }
    num2=result^num1;
    
    if(num1<num2){
        std::cout << num1<<" "<<num2 << std::endl;
    }else{
        std::cout << num2<<" "<<num1 << std::endl; 
    }

	return 0;
}