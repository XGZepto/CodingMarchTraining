#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[100000],b[100000],target,n;

void DFS(int i,int j,int sum){
	if (sum > target){
		return;
	}
	else if (sum == target){
		for (int p=0;p<j;p++){
			cout << b[p] << " ";
		}
		cout << endl;
		return;
	}
	for (int k=i;k<n;k++){
		/*while (a[k+1] == a[k] && k < n){
			k++;
		}*/
		b[j] = a[k];
		DFS(k+1,j+1,sum+a[k]);
	}
}

int main(){
	cin >> n >> target;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	DFS(0,0,0);
}