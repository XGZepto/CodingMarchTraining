#include <iostream>
using namespace std;
int main(){
    string ans="No";
    string s,t;
    cin>>s>>t;
    int s_pointer=0,t_pointer = 0;
    while (s_pointer<s.size()) {
        if (s[s_pointer] == t[t_pointer]) {
            t_pointer++;
            if (t_pointer == t.size()) {
                ans = "Yes";
            }
        }
        s_pointer++;
    }
    cout<<ans<<endl;
    return 0;
}
