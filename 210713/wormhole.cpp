#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;

int net[maxn], par[maxn],n;

// next -> +x

bool check(){
    for (int i = 1 ; i <= n ; ++i){
        int pos = i;
        do{
            pos = par[net[pos]];
        }while(pos!=i && pos);
        if (pos == i) return 1;
    }
    return 0;
}

