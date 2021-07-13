#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int a[2000][2000],cnt = 0;

void work(queue<pair<int,int>>& q,int i,int j,int n,int m){
	if (i < n && i >= 0 && j < m && j >= 0 && a[i][j] == 0){
		q.push(make_pair(i,j));
	}
	if (i == 0 && j == m - 1){
		cnt++;
	}
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for (int i=0;i<k;i++){
		int p,q;
		cin >> p >> q;
		a[p][q] = 1;
	}
	int i = n - 1,j = 0;
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	while (!q.size()){
		i = q.front().first;
		j = q.front().second;
		q.pop();
		work(q,i,j+1,n,m);
		work(q,i-1,j,n,m);
	}
	//cout << i << " " << j << endl;
	cout << cnt << endl;
}