#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int m[2000][2000],pos[2000][2000] = {0};
int siz[2000000];
int dis[200000];
int w, h;

void work(queue<pair<int,int>> &q,int i,int j,int id,int d){
	if (i < w && j < h && pos[i][j] == 0){
		int index = i + j * w;
		q.push(make_pair(i,j));
		pos[i][j] = id;
		siz[id]++;
		dis[index] = d;
	}
}

void BFS(int i, int j, int id){
	pos[i][j] = id;
	siz[id] = 1;
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	while (!q.size()){
		i = q.front().first, j = q.front().second;
		int index = i + j * w;
		q.pop();
		if (m[i][j]&1) work(q,i,j+1,id,dis[index]+1);
		if (m[i][j]&2) work(q,i,j-1,id,dis[index]+1);
		if (m[i][j]&4) work(q,i+1,j,id,dis[index]+1);
		if (m[i][j]&8) work(q,i-1,j,id,dis[index]+1);
	}
}

int main(){
	int tot;
	cin >> w >> h;
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			cin >> m[i][j];
		}
	}
	for (int i = 0 ; i < w ; ++i)
	for (int j = 0 ; j < h ; ++j)
		if (!pos[i][j]) BFS(i,j,++tot);
}