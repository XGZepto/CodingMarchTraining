#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct task{
    long duration;
    long endt;
};
task tasks[100005];
bool compare(task a,task b){
    return a.endt<b.endt;
}
long endtime=0;
int main(){ 
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>tasks[i].duration>>tasks[i].endt;
    }
    sort(tasks,tasks+n,compare);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (endtime+tasks[i].duration<=tasks[i].endt)
        {
            endtime += tasks[i].duration;
        }
        else{
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    return 0;
}