#include <iostream>
using namespace std;
int tolerance[100005];
int main(){
    int n,m;
    long total=0;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>tolerance[i];
        total += tolerance[i];
    }
    cout<<(total-m)*n<<endl;

    return 0;
}