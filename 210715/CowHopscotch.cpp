#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

char grid[15][15];
int cnt = 0;

void DFS(int r,int c,int x,int y){
	if (x == r - 1 && y == c - 1){
		cnt++;
		return;
	}
	if (x > r - 1 || y > c - 1){
		return;
	}
	for (int i=x+1;i<r;i++){
		for (int j=y+1;j<c;j++){
			if (grid[i][j] != grid[x][y]){
				DFS(r,c,i,j);
			}
		}
	}
}

int main(){
	int r,c;
	cin >> r >> c;
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			cin >> grid[i][j];
		}
	}
	DFS(r,c,0,0);
	cout << cnt << endl;
}