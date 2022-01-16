#include <bits/stdc++.h>
using namespace std;
string pack[2] = {"RSP", "RPS"};
string src;

int find(int s, string dic){
    int res = 0;
    for (auto x : src){
        if (x == dic[s]){
            res++;
            s = (s + 1) % 3;
        }
    }
    return res;
}

int main(){
    cin >> src;
    int ans = 0;
    ans = max(ans, find(0, pack[1]));
    ans = max(ans, find(1, pack[1]));
    ans = max(ans, find(2, pack[1]));
    ans = max(ans, find(0, pack[0]));
    ans = max(ans, find(1, pack[0]));
    ans = max(ans, find(2, pack[0]));
    cout << ans << endl;
    return 0;
}