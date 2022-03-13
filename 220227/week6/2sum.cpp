#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main(){
    int n;
    long M;
    cin>>n;
    cin>>M;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    sort(a,a+n);
    int i=0,j=n-1;
    long temp=a[0]+a[n-1];
    while (i<j)
    {
        if (abs(M-temp)>abs(M-a[i]-a[j]))
        {
            temp = a[i] + a[j];
        }
        if (a[i]+a[j]<M)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout<<abs(M-temp)<<endl;

    return 0;
}
