#include <iostream>
#include <algorithm>
using namespace std;
struct stop{
    int position;
    int point;
};
stop stops[100005];
long totalpoint=0;
bool compare(stop a,stop b){
    if (a.point>b.point)
    {
        return true;
    }
    else if(a.point == b.point){
        if (a.position>b.position)
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
int main(){
    int l,n,Vf,Vb;
    cin>>l>>n>>Vf>>Vb;
    for (int i = 0; i < n; i++)
    {
        cin>>stops[i].position>>stops[i].point;
    }
    sort(stops,stops+n,compare);
    int laststop =0;
    long alreadyused=0;
    for (int i = 0; i < n; i++)
    {
        if (stops[i].position<laststop)
        {
            continue;
        }
        else{
            totalpoint += stops[i].point * ((Vf-Vb)*stops[i].position-alreadyused);
            alreadyused += (Vf-Vb)*stops[i].position;
        }
    }
    cout<<totalpoint<<endl;

    return 0;
}