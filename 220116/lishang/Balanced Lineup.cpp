#include <iostream>
#include <cmath>
//#include <fstream>
using namespace std;
int heights[50005];
int maximum[50000][20];
int minimum[50000][20];
int answers[200005];

int main(){
//    ifstream fin("beads.in");
//    ofstream fout("beads.out");
    int n,p;
    cin>>n>>p;
    for (int i=1; i<=n; i++) {
        cin>>heights[i];
    }
    for (int i=1; i<=n; i++) {
        maximum[i][0] = heights[i];
        minimum[i][0] = heights[i];
    }
    for (int j=1; j<=int(log(n)/log(2)); j++) {
        for (int i=1; i<=n-int(pow(2, j))+1; i++) {
            maximum[i][j] = max(maximum[i][j-1],maximum[i+int(pow(2, j-1))][j-1]);
            minimum[i][j] = min(minimum[i][j-1],minimum[i+int(pow(2, j-1))][j-1]);
        }
    }
    int lowerbound,upperbound,len;
    int largest_e;
    for(int i=0;i<p;i++){
        cin>>lowerbound>>upperbound;
        len = upperbound-lowerbound+1;
        largest_e = int(log(len)/log(2));
        answers[i] =
            max(maximum[lowerbound][largest_e],
                maximum[upperbound-int(pow(2,largest_e))+1][largest_e])-
            min(minimum[lowerbound][largest_e], minimum[upperbound-int(pow(2,largest_e))+1][largest_e]);
    }
    for (int i=0; i<p; i++) {
        cout<<answers[i]<<endl;
    }
    return 0;
}
