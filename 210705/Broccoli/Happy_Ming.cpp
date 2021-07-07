#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct item{
	int v,p,s;
}a[25];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i=0;i<m;i++){
		cin >> a[i].v >> a[i].p;
		a[i].s = a[i].v * a[i].p;
	}
	int dp[30001] = {0};
	int vis[30001][25] = {0};
	for (int i=1;i<=n;i++){
		for (int j=0;j<m;j++){
			if (i - a[j].v >= 0){
				if (vis[i-a[j].v][j] == 1){
					if (dp[i-a[j].v] > dp[i]){
						dp[i] = dp[i-a[j].v];
						for (int k=0;k<m;k++){
							vis[i][k] = vis[i-a[j].v][k];
						}
					}
				}
				else{
					if (dp[i-a[j].v] + a[j].s > dp[i]){
						dp[i] = dp[i-a[j].v] + a[j].s;
						for (int k=0;k<m;k++){
							vis[i][k] = vis[i-a[j].v][k];
						}
						vis[i][j]++;
					}
				}
			}
		}
	}
	//cout << vis[700][0] << vis[700][1] << vis[700][2] << vis[700][3] << vis[700][4] << endl;
	cout << dp[n] << endl;
	return 0;
}