#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;

int vis[100] = {0}, cnt = 0;

void split_num(int n,int a){
	if (a == n){
		cnt++;
		//cout << endl;
		return;
	}
	int k = n;
	while (vis[k] == 0 && k >= 1){
		k--;
	}
	for (int i=k+1;i<=n;i++){
		if (i + a > n){
			return;
		}
		if (vis[i] == 0){
			//cout << i << " ";
			a += i;
			vis[i] = 1;
			split_num(n,a);
			a -= i;
			vis[i] = 0;
		}
	}
}

int main(){
	int n;
	cin >> n;
	split_num(n,0);
	cout << cnt << endl;
}