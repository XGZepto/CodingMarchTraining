#include <bits/stdc++.h>
using namespace std;

int Work();

int a[100];

int main(){
    int T_T;
    cin >> T_T;
    while(T_T--) printf("%d\n", Work());
}

int Work(){
    int n, x, cnt = 0, res = 0;
    map<int, bool>vis;
    cin >> n;
    for (int i = 1 ; i <= n ; ++i){
        cin >> x;
        if (!vis.count(x)) vis[x] = 1, cnt++;
    }
    if (cnt == 1) res = 1;
    else if (cnt == n) res = -1;
    return res;
}