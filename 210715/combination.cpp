#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int all[20],a[20];

void choose(int n,int k,int begin,int maxi){
	if (begin == k){
		for (int i=0;i<k-1;i++){
			cout << a[i] << " ";
		}
		cout << a[k-1] << endl;
		return;
	}
	for (int i=maxi;i<n;i++){
		a[begin] = all[i];
		choose(n,k,begin+1,i+1);
		a[begin] = 0;
	}
}

int main(){
	int n,k;
	cin >> n >> k;
	for (int i=0;i<n;i++){
		cin >> all[i];
	}
	sort(all,all+n);
	choose(n,k,0,0);
}