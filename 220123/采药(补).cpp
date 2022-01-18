#include <iostream>
using namespace std;
int dp[105][1005];
struct herb{
    int cost;
    int value;
};
herb herbs[105];
int t,m;
int main(){
    cin>>t>>m;  
    for (int i=1; i<=m; i++) {
        cin>>herbs[i].cost>>herbs[i].value;
    }
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=t; j++) {
            if (i==0) {
                dp[i][j] = 0;
            }
            else if(j==0){
                dp[i][j] = 0;
            }
            else{
                //判断能不能拿得了这个新东西
                if (j>=herbs[i].cost) {
                    dp[i][j] = max(dp[i-1][j], herbs[i].value + dp[i-1][j-herbs[i].cost]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }
    }
    cout<<dp[m][t]<<endl;
    return 0;
}
