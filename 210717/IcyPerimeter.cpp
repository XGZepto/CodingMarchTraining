#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

char p[1000][1000];
int cnt = 1, max_p = 0, pos[1000][1000] = {0};
queue<pair<int,int>> q;

bool done(int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (pos[i][j] == 0 && p[i][j] == '#'){
				return false;
			}
		}
	}
	return true;
}

void work(int i,int j,int n){
	if (i >= 0 && i < n && j >= 0 && j < n && pos[i][j] == 0 && p[i][j] == '#'){
		q.push(make_pair(i,j));
		pos[i][j] = cnt;
	}
}

int parameter(int cnt,int n,int i,int j){
	int res = 4;
	if (i - 1 >= 0 && p[i-1][j] == cnt){
		res--;
	}
	if (i + 1 < n && p[i+1][j] == cnt){
		res--;
	}
	if (j - 1 >= 0 && p[i][j-1] == cnt){
		res--;
	}
	if (j + 1 < n && p[i][j+1] == cnt){
		res--;
	}
	return res;
}

int parameter_all(int cnt,int n){
	int ans = 0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (p[i][j] == cnt){
				ans += parameter(cnt,n,i,j);
			}
		}
	}
	return ans;
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
				work(a,b+1,n);
				work(a,b-1,n);
				work(a+1,b,n);
				work(a-1,b,n);
			}
		}
		else{
			cnt++;
			max_p = max(max_p,parameter_all(cnt,n));
			int f = 0;
			for (int i=0;i<n;i++){
				if (f > 0){
					break;
				}
				for (int j=0;j<n;j++){
					if (pos[i][j] == 0 && p[i][j] == '#'){
						q.push(make_pair(i,j));
						pos[i][j] = cnt;
						f++;
						break;
					}
				}
			}
		}
	}
	cout << max_p << endl;
}
