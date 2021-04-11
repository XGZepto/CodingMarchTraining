//
//  main.cpp
//  AAABAC
//
//  Created by 姚欣 on 2021/4/4.
//  Copyright © 2021 任奕霏. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int t,i;
    cin >> t;
    for(i = 0; i < t; i ++)
    {
        long long x,temp = 26;
        cin >> x;
        int j = 1;
        x --;
        while(x >= 1ll * j * temp)
        {
            x -= 1ll * j * temp;
            j ++;
            temp *= 26;
        }
        int length = j;
        long long position = x / j,pos = x % j;
        int a[length],k;
        for(k = 0; k < length; k ++)
        {
            a[k] = position % 26;
            position /= 26;
        }
        cout << char(a[length - 1 - pos] + 'A') << endl;
    }
    return 0;
}
