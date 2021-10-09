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
        // i = 13
        long long temp = 1ll * i * i;
        // temp = 169;

        // temporary
        
        string buff = to_string(temp);
        // buff = "169";
        sort(buff.begin(), buff.end());
        // 
        ans += cnt[buff]++;
        // ans+= cnt[buff];
        // cnt[buf]++;
    }
    printf("%lld\n", ans);
}
