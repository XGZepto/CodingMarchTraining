#include <iostream>
using namespace std;

string s;

void Work(){
    cin >> s;
    int count = 0;
    for(int j = 0; j < s.size() / 2; j ++)
        if(s[j] != s[s.size() - j - 1])
            count ++;
    if(s.size() % 2 == 0 && count % 2 != 0)
        cout << -1 << endl;
    else
        cout << (count + 1) / 2 << endl;
}

int main(){
    int T_T;
    cin >> T_T;
    while(T_T--) Work();
    return 0;
}