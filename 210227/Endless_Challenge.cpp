#include <iostream>
#include <cstdio>

typedef long long ll;
const int maxn = 1e5 + 1;
int n, q, k;
ll sum[maxn];

int main(){
    scanf("%d%d", &n, &q);
    for (int i = 1 ; i <= n ; ++i)
        scanf("%lld", sum + i),
        sum[i] += sum[i - 1];
    for (int i = 1 ; i <= q ; ++i){
        scanf("%d", &k);
        int round = k / n;
        int lef = k % n;
        ll res = 1ll * sum[n] * round + 1ll * n * (round - 1) * round / 2;
        res += sum[lef] + 1ll * round * lef;
        printf("%lld\n", res);
    }
    return 0;
}