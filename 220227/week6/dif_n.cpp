#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
long long func1(int n){
    return 9*pow(10,n-1);
}
long long func2(int n){
    if (n>10)
    {
        return 0;
    }
    else if(n==1){
        return 9;
    }
    else{
        long long ans=1;
        for (int i = 0; i < n; i++)
        {  
            if (i==0)
            {
                ans *= (10-n+1);
            }
            else{
                ans *= (10-n+i);
            }
        }
        return ans;
    }
}
long long func3(int n){
    if (n>1)
    {
        return 5*pow(10,n-2)*9;
    }
    else{
        return 4;
    }
}
long long func4(int n){
    if (n>10)
    {
        return 0;
    }
    else if (n==1){
        return 4;
    }
    else{
        long long ans=1;
        ans*=5;
        for (int i = 0; i < n-1; i++)
        {
            if (i==0)
            {
                ans*=8;
            }
            else{
                ans*=(10-1-i);
            }
        }
        return ans;
    }
    
}
int main(){
    int n;
    cin>>n;
    cout<<func1(n)<<endl<<func2(n)<<endl<<func3(n)<<endl<<func4(n)<<endl;
    return 0;
}