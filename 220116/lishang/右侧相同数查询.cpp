#include <iostream>
using namespace std;
int numbers[100005];
int number_in_total[100005];
int number_in_left[100005];
int answers[100005];
int main(){
    int n;
    cin>>n;
    //右边有多少个数 = 一共有多少个这个数 - 左边有多少个这个数
    for (int i=0; i<n; i++) {
        cin>>numbers[i];
        number_in_total[numbers[i]]++;
        number_in_left[i] = number_in_total[numbers[i]];
    }
    int q;
    cin>>q;
    int enquiry;
    for (int i=0; i<q; i++) {
        cin>>enquiry;
        answers[i] = number_in_total[numbers[enquiry-1]] - number_in_left[enquiry-1];
    }
    for (int i=0; i<q; i++) {
        cout<<answers[i]<<endl;
    }
    
    
    
    
    return 0;
}

