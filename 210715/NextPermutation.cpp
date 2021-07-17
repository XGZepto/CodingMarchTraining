#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

int a[100];

void find_next(int n,int begin){
	if (begin == n - 1){
		for (int i=0;i<n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i=begin;i<n;i++){
		if (a[i] <= a[begin]){
			continue;
		}
		swap(a[begin],a[i]);
		find_next(n,begin+1);
		swap(a[begin],a[i]);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
}