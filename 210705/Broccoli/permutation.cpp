#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void work(string s,int begin,int l,vector<string>& res){
	if (begin == l){
		res.push_back(s);
		return;
	}
	for (int i=begin;i<=l;i++){
		if (begin != i && s[begin] == s[i]){
			continue;
		}
		swap(s[begin],s[i]);
		work(s,begin+1,l,res);
		swap(s[begin],s[i]);
	}
}

vector<string> permutation(string s){
	vector<string> res;
	if (s.size() == 0){
		return res;
	}
	int l = s.size() - 1;
	work(s,0,l,res);
	return res;
}

int main(){
	string s;
	cin >> s;
	vector<string> res = permutation(s);
	for (int i=0;i<res.size();i++){
		cout << res[i] << endl;
	}
}