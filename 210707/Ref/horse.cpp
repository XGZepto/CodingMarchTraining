#include <bits/stdc++.h>

const int maxn = 1e6 + 1;

int dis[maxn];

void work(){
    //j -> k

    // j := head
    // k -> next_pos

    if (dis[k] > dis[j] + 1){
        dis[k] = dis[j] + 1;
        //push
    }
}