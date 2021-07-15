#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int open[3001] = {0},vis[3001] = {0};
vector<int> to[3001];

bool connected(int n,int k,int a,int fa,int num){
	vis[a] = 1;
	if (n - k == num){
		return true;
	}
	int l = to[a].size();
	for (int i=0;i<l;i++){
		if (open[to[a][i]] == 0 && to[a][i] != fa){
			vis[to[a][i]]++;
			num++;
			connected(n,k,to[a][i],a,num);
		}
	}
	return false;
}

int main(){
	int n,m;
	cin >> n >> m;
	for (int i=0;i<m;i++){
		int p,q;
		cin >> p >> q;
		to[p].push_back(q);
		to[q].push_back(p);
	}
	if (connected(n,0,1,0,1)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	memset(vis,0,sizeof(vis));

	for (int i=1;i<n;i++){
		int p;
		cin >> p;
		open[p]++;
		if (connected(n,i,1,0,1)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		memset(vis,0,sizeof(vis));		
	}
	int p;
	cin >> p;
	return 0;
}