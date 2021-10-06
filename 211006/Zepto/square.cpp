// Square Permutation
// Zepto
// 06 Oct 2021

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> cnt;
long long ans, n;

int main(){
    scanf("%lld", &n);
    for (register int i = 1; 1ll * i * i <= n; ++i){
        long long temp = 1ll * i * i;
        string buff = to_string(temp);
        sort(buff.begin(), buff.end());
        ans += cnt[buff]++;
    }
    printf("%lld\n", ans);
}
