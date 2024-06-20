#include<iostream>
using namespace std;
long long power(int a ,int n){
      if (n==0){
            return 1;
      }
      else if (n==1){
            return a;
      }
      else{
            long long R = power(a,n/2);
            if (n%2 == 0)
            {
                  return R*R;
            }
            else
            return R*a*R;
      }
}
int main(){
      int a,n;
      cout<<"enter base(a):";
      cin>>a;
      cout<<"enter exponent(n):";
      cin>>n;
      long long value = power(a,n);
      cout<<"valve is:"<<value;
      return 0;
}