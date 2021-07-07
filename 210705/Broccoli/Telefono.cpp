#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char dial[10][4] = {{'a','a','a','a'}, {'a','a','a','a'}, {'A','B','C','a'},{'D','E','F','a'},{'G','H','I','a'},{'J','K','L','a'},{'M','N','O','a'},{'P','Q','R','S'},{'T','U','V','a'},{'W','X','Y','Z'}};

void permutation(string s,int a[],int n,int k){
	if (k == n - 1){
		for (int i=0;i<n;i++){
			cout << dial[s[i]-'0'][a[i]];
		}
		cout << endl;
		return;
	}
	for (int i=k;i<n;i++){
		a[i]++;
		permutation(s,a,n,k+1);
		a[i]--;
	}
}

int main(){
	string s;
	cin >> s;
	int l = s.size();
	int a[10] = {0};
	permutation(s,a,l,0);
}