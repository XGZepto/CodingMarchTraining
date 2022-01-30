//
//  main.cpp
//  导弹拦截
//
//  Created by 李泽建 on 1/28/22.
//

#include <iostream>
#include <cstdio>
int mis[10001],up[10001],down[10001];
using namespace std;
int main(){
    int n; cin>>n;
    int maxn,minn;
    for(int i=1;i<=n;i++){
        cin>>mis[i];
        up[i]=down[i]=1;
        for(int j=1;j<i;j++){
            if(mis[i]<=mis[j]) up[i]=max(up[i],up[j]+1);
            if(mis[i]>mis[j]) down[i]=max(down[i],down[j]+1);
        }
        if(up[i]>maxn）maxn=up[i];
        if(down[i]>minn) minn=down[i];
    }
    cout<<maxn<<minn<<endl;
    return 0;
}
