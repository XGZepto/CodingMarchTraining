#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;

int vis[101] = {0}, cnt = 0;

void split_num(int n,int a,int k){
	if (a == n){
		cnt++;
		//cout << endl;
		return;
	}
	for (int i=k+1;i<=n;i++){
		if (i + a > n){
			return;
		}
		if (vis[i] == 0){
			a += i;
			vis[i] = 1;
			split_num(n,a,i);
			a -= i;
			vis[i] = 0;
		}
	}
}

int main(){
	int n;
	cin >> n;
	split_num(n,0,0);
	cout << cnt << endl;
}