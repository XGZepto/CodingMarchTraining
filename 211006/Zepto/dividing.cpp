#include <bits/stdc++.h>
using namespace std;
#define ls (p<<1)

typedef long long ll;

const int maxn = 2e5 + 10;

int N, M;
int a[maxn];
bool w[maxn];

int quick_pow(int m, int n){
    int res = 1;
    while(n){
        if (n%2) res *= m;
        m *= m, n /= 2;
    }
    return res;
}

int main(){
    cout << quick_pow(7, 4) << endl;
    // scanf("%d%d", &N, &M);
    // for (int i = 1 ; i <= N ; ++i)
    //     scanf("%d", a + i);
    // for (int i = 1, temp = 0 ; i <= M ; ++i){
    //     scanf("%d", &temp);
    //     w[temp] = 1;
    // }
    // long long l_sum = 0, r_sum = 0;
    // long long ans = -1;
    // int l =0, r = N + 1;
    // while(l < r){
    //     if (l_sum == r_sum){
    //         if (w[r - l - 1]) 
    //             ans = max(ans, l_sum);
    //     }

    //     if (l_sum <= r_sum){
    //         l++;
    //         l_sum += a[l];
    //     }
    //     else {
    //         r--;
    //         r_sum += a[r];
    //     }
    // }
    // printf("%lld\n", ans);
    return 0;
}