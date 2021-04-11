#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int k, ans, cnt;

int main(){
    cin >> s >> k;
    for (int i = 0 ; i < s.size() ; ++i){
        if (s[i] != s[i + k]) cnt++;
        else ans = max(ans, cnt + k), cnt = 0;
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}