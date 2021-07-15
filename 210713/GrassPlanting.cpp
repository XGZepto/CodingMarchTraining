#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<int> to[maxn];
int cnt = 1,maxi = 1;

void plant(int n,int a,int fa,int num){
	if (maxi < cnt){
		maxi = cnt;
	}
	if (num == n){
		cout << maxi << endl;
		return;
	}
	int l = to[a].size();
	cnt += l - 1;
	num += l - 1;
	for (int i=0;i<l;i++){
		int b = to[a][i];
		if (b != fa){
			if (to[b].size() > l){
				cnt = cnt - (l - 1) + (to[b].size() - 1);
				num += to[b].size() - 1;
				plant(n,to[a][i],a,num);
				cnt = cnt + (l - 1) - (to[b].size() - 1);
			}
			else{
				num += to[b].size() - 1;
				plant(n,to[a][i],a,num);
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	for (int i=0;i<n-1;i++){
		int p,q;
		cin >> p >> q;
		to[p].push_back(q);
		to[q].push_back(p);
	}
	cnt += to[1].size();
	plant(n,1,1,1+to[1].size());
}