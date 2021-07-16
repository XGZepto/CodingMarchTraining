#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

char p[100][100];
int cnt = 0, pos[100][100] = {0};
queue<pair<int,int>> q;

bool done(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (pos[i][j] == 0){
				return false;
			}
		}
	}
	return true;
}

void work_human(queue<pair<int,int>>& q,int a,int b,int i,int j,int n){
	if (i >= 0 && i < n && j >= 0 && j < n && pos[i][j] == 0){
		if (p[i][j] == p[a][b]){
			q.push(make_pair(i,j));
			pos[i][j] = 1;
		}
	}
}

void work_cow(queue<pair<int,int>>& q,int a,int b,int i,int j,int n){
	if (i >= 0 && i < n && j >= 0 && j < n && pos[i][j] == 0){
		if (p[i][j] == p[a][b] || p[i][j] == 'G' && p[a][b] == 'R' || p[i][j] == 'R' && p[a][b] == 'G'){
			q.push(make_pair(i,j));
			pos[i][j] = 1;
		}
	}
}

void clear_all(int n){
	cnt = 0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			pos[i][j] = 0;
		}
	}
	while (q.size()){
		q.pop();
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin >> p[i][j];
		}
	}
	int a = 0,b = 0;
	pos[a][b] = 1;
	cnt++;
	q.push(make_pair(a,b));
	while (!done(n)){
		if (q.size()){
			while (q.size()){
				a = q.front().first;
				b = q.front().second;
				q.pop();
				work_human(q,a,b,a,b+1,n);
				work_human(q,a,b,a,b-1,n);
				work_human(q,a,b,a+1,b,n);
				work_human(q,a,b,a-1,b,n);
			}
		}
		else{
			cnt++;
			int f = 0;
			for (int i=0;i<n;i++){
				if (f > 0){
					break;
				}
				for (int j=0;j<n;j++){
					if (pos[i][j] == 0){
						q.push(make_pair(i,j));
						pos[i][j] = 1;
						f++;
						break;
					}
				}
			}
		}
	}
	cout << cnt << " ";

	clear_all(n);
	a = 0,b = 0;
	pos[a][b] = 1;
	cnt++;
	q.push(make_pair(a,b));
	while (!done(n)){
		if (q.size()){
			while (q.size()){
				a = q.front().first;
				b = q.front().second;
				q.pop();
				work_cow(q,a,b,a,b+1,n);
				work_cow(q,a,b,a,b-1,n);
				work_cow(q,a,b,a+1,b,n);
				work_cow(q,a,b,a-1,b,n);
			}
		}
		else{
			cnt++;
			int f = 0;
			for (int i=0;i<n;i++){
				if (f > 0){
					break;
				}
				for (int j=0;j<n;j++){
					if (pos[i][j] == 0){
						q.push(make_pair(i,j));
						pos[i][j] = 1;
						f++;
						break;
					}
				}
			}
		}
	}
	cout << cnt << endl;
}