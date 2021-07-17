#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;
const int maxn = 15;

int net[maxn],par[maxn],n,cnt = 0;

bool check(){
	for (int i=1;i<=n;i++){
		int pos = i;
		do{
			pos = par[net[pos]];
		}while (pos != i && pos);
		if (pos == i) return 1;
	}
	return 0;
}

void DFS(int coo[][2],int a){
	while(par[a]) a++;

	if (a == n){
		cnt += check();
		return;
	}
	
	for (int i=a+1;i<n;i++){
		if (!par[i]){
			par[a] = i;
			par[i] = a;
			DFS(coo,a+1);
			par[a] = 0;
			par[i] = 0;
		}
	}
}

int main(){
	cin >> n;
	int coo[n][2];
	for (int i=0;i<n;i++){
		cin >> coo[i][0] >> coo[i][1];
	}
	for (int i=0;i<n;i++){
		net[i] = 1e9;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (coo[i][1] == coo[j][1] && coo[i][0] < coo[j][0] && coo[net[i]][0] > coo[j][0]){
				net[i] = j;
			}
		}
	}
	DFS(coo,0);
	cout << cnt << endl;
}