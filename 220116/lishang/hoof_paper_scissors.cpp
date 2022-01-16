#include <iostream>
#include <fstream>
using namespace std;
struct counter{
    char current;
    //p h s
    int p=0;
    int h=0;
    int s=0;
};
struct total_counter{
    int p=0;
    int h=0;
    int s=0;
};
total_counter total_counters;
counter gestures[100005];
int main(){
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>gestures[i].current;
        if (i==1) {
            if (gestures[i].current == 'P') {
                gestures[i].p = 1;
                total_counters.p++;
            }
            else if (gestures[i].current == 'H') {
                gestures[i].h = 1;
                total_counters.h++;
            }
            else if (gestures[i].current == 'S') {
                gestures[i].s = 1;
                total_counters.s++;
            }
        }
        else{
            if (gestures[i].current == 'P') {
                gestures[i].p = gestures[i-1].p+1;
                total_counters.p++;
            }
            else if (gestures[i].current == 'H') {
                gestures[i].h = gestures[i-1].h+1;
                total_counters.h++;
            }
            else if (gestures[i].current == 'S') {
                gestures[i].s = gestures[i-1].s+1;
                total_counters.s++;
            }
        }
    }
    int max_wins = 0;
    int wins = 0;
    for (int i=1; i<=n; i++) {
        wins = max(gestures[i].p, max(gestures[i].h, gestures[i].s)) + max(total_counters.p - gestures[i].p, max(total_counters.h-gestures[i].h,total_counters.s-gestures[i].s));
        if (wins>max_wins) {
            max_wins = wins;
        }
    }
    cout<<max_wins<<endl;
    
    return 0;
}
