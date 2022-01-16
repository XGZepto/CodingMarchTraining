#include <iostream>
using namespace std;
int times_counter[10005];
int answers[100005];
int numbers[100005];
int ans_pointer;
int main(){
    int n,q;
    cin>>n>>q;
    for (int i=0; i<n; i++) {
        cin>>numbers[i];
        times_counter[numbers[i]]++;
    }
    int operat,argument1,argument2;
    for (int i=0; i<q; i++) {
        cin>>operat;
        if (operat == 2) {
            cin>>argument1;
            answers[ans_pointer] = times_counter[argument1];
            ans_pointer++;
        }
        else{
            cin>>argument1>>argument2;
            times_counter[numbers[argument1-1]]--;
            times_counter[argument2]++;
            numbers[argument1-1] = argument2;
        }
    }
    for (int i=0; i<ans_pointer; i++) {
        cout<<answers[i]<<endl;
    }
    
    
    return 0;
}
