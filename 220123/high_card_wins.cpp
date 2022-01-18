#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int elsie[50005];
int bessie[50005];
int bessie_poionter=0;
int cards[100005];
int ans=0;
int main(){
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    int n;
    fin>>n;
    for (int i=0; i<n; i++) {
        fin>>elsie[i];
        cards[elsie[i]] = 1;
    }
    for (int i=1; i<=2*n; i++) {
        if (cards[i]!=1) {
            cards[i] = 2;
            bessie[bessie_poionter] = i;
            bessie_poionter++;
        }
    }
    sort(bessie, bessie+bessie_poionter);
    sort(elsie, elsie+n);
    //1 4 6
    //2 3 5
    int bessie_card_pointer=0;
    for (int i=0; i<n; i++) {
        while (elsie[i]>bessie[bessie_card_pointer] && bessie_card_pointer<n) {
            bessie_card_pointer++;
        }
        if (bessie_card_pointer>=n) {
            break;
        }
        ans++;
        bessie_card_pointer++;
    }
    fout<<ans<<endl;
    
    return 0;
}
