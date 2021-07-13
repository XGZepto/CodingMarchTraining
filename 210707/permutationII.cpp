#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int a[8];

void permutation(int a[],int begin,int n){
	if (begin == n - 1){
		for (int i=0;i<n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i=begin;i<n;i++){
		if (begin != i && a[begin] == a[i]){
			continue;
		}
		swap(a[begin],a[i]);
		permutation(a,begin+1,n);
		swap(a[begin],a[i]);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	permutation(a,0,n);
}