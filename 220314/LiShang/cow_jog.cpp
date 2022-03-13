#include <iostream>
using namespace std;
struct cow{
    int position;
    int speed;
};
int slowest = 0;
int no=1;
cow cows[100005];
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>cows[i].position>>cows[i].speed;
    }
    for (int i = n-1; i >=0; i--)
    {
        if (i == n-1)
        {
            slowest = cows[i].speed;
        }
        else{
            if (cows[i].speed>slowest)
            {
                continue;
            }
            else{
                no++;
                slowest = cows[i].speed;
            }
        }
        
    }
    cout<<no<<endl;
    

    return 0;
}