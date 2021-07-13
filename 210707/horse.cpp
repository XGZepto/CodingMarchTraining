#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1e6 + 1;
int dis[1001][1001];

void work(queue<pair<int,int>>& q,int i,int j,int x,int y,int n,int m){
	if (i >= 1 && i <= n && j >= 1 && j <= m && dis[i][j] > dis[x][y] + 1){
		dis[i][j] = dis[x][y] + 1;
		q.push(make_pair(i,j));
	}
	return;
}

int main(){
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			dis[i][j] = maxn;
		}
	}
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	dis[x][y] = 0;
	while (q.size()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		work(q,x-2,y-1,x,y,n,m);
		work(q,x+2,y-1,x,y,n,m);
		work(q,x-2,y+1,x,y,n,m);
		work(q,x+2,y+1,x,y,n,m);
		work(q,x-1,y-2,x,y,n,m);
		work(q,x-1,y+2,x,y,n,m);
		work(q,x+1,y-2,x,y,n,m);
		work(q,x+1,y+2,x,y,n,m);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (dis[i][j] == maxn){
				cout << -1 << " ";
			}
			else{
				cout << dis[i][j] << " ";
			}
		}
		cout << endl;
	}
}