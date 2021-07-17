#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int fast_pow(int x,int y){
	int res = 1;
	while (y > 0){
		if (y & 1){
			res = res * x;
		}
		y = y / 2;
		x = x * x;
	}
	return res;
}

int find_power(int a,int n,int l,int r){
	if (n == 1){
		return a;
	}
	if (l > r){
		return -1;
	}
	int k = (l + r) / 2;
	if (fast_pow(k,n) < a){
		find_power(a,n,k+1,r);
	}
	else if (fast_pow(k,n) > a){
		find_power(a,n,l,k-1);
	}
	else{
		return k;
	}
}

int main(){
	int a,n;
	cin >> a >> n;
	cout << find_power(a,n,1,1e9);
}