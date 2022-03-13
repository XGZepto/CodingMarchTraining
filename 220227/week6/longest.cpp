#include <iostream>
#include <cmath>
using namespace std;
int a[100005];
int main(){
    long modulus = pow(10,9)+7;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    bool positive=a[0]>0;
    long long ans=1;
    long temp=0;
    int length=1;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>0 == positive)
        {
            temp++;
            if (i==n-1)
            {
                ans*=temp;
                ans %= modulus;
            }
            
        }
        else{
            ans*=temp;
            ans %= modulus;
            temp = 1;
            length++;
            positive = a[i]>0;
        }
    }
    cout<<length<<endl<<ans<<endl;

    return 0;
}