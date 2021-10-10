#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cnt;

int main(){
    int n, x;
    long long ans = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x);
        cnt[x]++;
        ans += max(cnt[x] - 2, 0);
    }
    printf("%lld\n", ans);
    return 0;
}