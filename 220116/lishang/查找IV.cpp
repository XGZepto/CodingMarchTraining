#include <iostream>
using namespace std;
int positions[10005];
int answers[10005];
int main(){
    for (int i=0; i<10005; i++) {
        positions[i] = -1;
    }
    int n;
    cin>>n;
    int number;
    for (int i=0; i<n; i++) {
        cin>>number;
        positions[number] = i+1;
    }
    int q;
    cin>>q;
    int enquiry;
    for (int i=0; i<q; i++) {
        cin>>enquiry;
        answers[i] = positions[enquiry];
    }
    for (int i=0; i<q; i++) {
        cout<<answers[i]<<endl;
    }
    
    return 0;
}
