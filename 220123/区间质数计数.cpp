#include <iostream>
using namespace std;
char numbers[10000005];
long answers[100005];
void init(long n){
    for (int i=0; i<=n; i++) {
        numbers[i] = 'Y';
    }
}
long no_primes(long n){
    long ans = 0;
    init(n);
    if (n==1) {
        return 0;
    }
    for (int i=2; i<=n; i++) {
        if (numbers[i] == 'Y') {
            ans++;
            long counter = 2;
            while (i*counter<=n) {
                numbers[i*counter] = 'N';
                counter++;
            }
        }
    }
    return ans;
}
int main(){
    int q;
    cin>>q;
    long lowerbound,upperbound;
    for (int i=0; i<q; i++) {
        cin>>lowerbound>>upperbound;
        answers[i] = no_primes(upperbound) - no_primes(lowerbound-1);
    }
    for (int i=0; i<q; i++) {
        cout<<answers[i]<<endl;
    }
//    cout<<no_primes(9)<<endl;
    
    return 0;
}
