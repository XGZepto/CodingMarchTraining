#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int m[2000][2000],pos[2000][2000] = {0};

void work(queue<pair<int,int>> q,int i,int j,int w,int h){
	if (i < w && j < h && pos[i][j] == 0){
		q.push(make_pair<i,j>);
		pos[i][j] = 1;
	}
}

int main(){
	int w,h;
	cin >> w >> h;
	for (int i=0;i<h;i++){
		for (int j=0;j<w;j++){
			cin >> m[i][j];
		}
	}
	int i=0,j=0;
	queue<pair<int,int>> q;
	while (!q.size()){
		q.pop();
		work(q,i,j+1,w,h);
		work(q,i,j-1,w,h);
		work(q,i+1,j,w,h);
		work(q,i-1,j,w,h);
	}
}