#include <bits/stdc++.h>

int a[21], n, k;

void work(int *b, int len, int pos){
    if (len > k){
        for (int i = 1 ; i <= k ; ++i)
            printf("%d ", b[i]);
        putchar('\n');
        return;
    }
    for (int i = pos ; i <= n ; ++i){
        b[len] = a[i];
        work(b, len+1, i+1);
    }
}

int main(){
    
}