#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;

const int maxn = 1e5;
int a[maxn];

bool GCD(int a[],int n,int k){
	int remainder = a[0] % k;
	for (int i=1;i<n;i++){
		if (a[i] % k != remainder){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int min1 = 1e9, min2 = 1e9;
	for (int i=0;i<n;i++){
		cin >> a[i];
		if (a[i] < min1){
			min2 = min1;
			min1 = a[i];
		}
		else if (a[i] < min2 && a[i] > min1){
			min2 = a[i];
		}
	}
	int k = min2 - 1;
	while (!GCD(a,n,k)){
		k--;
	}
	cout << k << endl;
}