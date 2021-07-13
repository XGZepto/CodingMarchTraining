#include <bits/stdc++.h>
using namespace std;

int a[5000], tot;

void DFS(int n,vector<int> to[],int begin,int fa){
	// if (to[begin].size() == 0 || i == n - 1){
	// 	return;
	// }
	a[tot++] = begin;
	int l = to[begin].size();
	for (int j = 0 ; j < l ; j++){
		int next = to[begin][j];
		if (next==fa) continue;
		DFS(n,to,next,begin);
	}
	// a[i] = mini;
	// DFS(n,to,mini,i+1);
	
}

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> to[n+1];
	for (int i=0;i<m;i++){
		int p,q;
		cin >> p >> q;
		to[p].push_back(q);
		to[q].push_back(p);
	}
	for (int i = 1 ; i <= n ; ++i)
		sort(to[i].begin(), to[i].end());
	DFS(n,to,1,1);
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}