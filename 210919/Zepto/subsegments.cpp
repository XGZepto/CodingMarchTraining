#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;

int N, M, K;
int A[maxn];

int main(){
    int sum = 0, ans = 0;
    scanf("%d%d%d",&N, &M, &K);
    for (int i = 0 ; i < N ; ++i){
        scanf("%d", A + i);
        if (A[i] > M) A[i] = 1;
            else A[i] = 0;
        if (i < K) sum += A[i];
    }
    ans += sum == 0;
    for (int i = K; i < N ; ++i){
        sum -= A[i - K];
        sum += A[i];
        ans += sum == 0;
    }
    printf("%d\n", ans);
    return 0;
}