#include <iostream>
using namespace std;
long numbers[100005];
long long sum = 0;
long long largest = 0;
int main(){
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>numbers[i];
    }
    for (int i = n-k; i < n; i++)
    {
        sum += numbers[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i<k)
        {
            sum = sum + numbers[i] - numbers[n-k+i];
        }
        else{
            sum = sum + numbers[i] - numbers[i-k];
        }
        if (sum>largest)
        {
            largest = sum;
        }   
    }
    cout<<largest<<endl;



    return 0;
}