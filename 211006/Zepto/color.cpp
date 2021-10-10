#include <bits/stdc++.h>
using namespace std;

string x;
int n;

int Find(char t){
    int leftmost = -1, rightmost = -1;
    for (int i = 0 ; i < n ; ++i)
        if (x[i] == t){
            leftmost = i;
            break;
        }
    for (int i = n - 1 ; i >=0 ; --i)
        if (x[i] == t){
            rightmost = i;
            break;
        }
    if (leftmost == -1) return 0;
    while(leftmost > 0 && x[leftmost - 1] == '?') leftmost--;
    while(rightmost < n - 1 && x[rightmost + 1] == '?') rightmost++;
    return rightmost - leftmost + 1;
}

int Solve(){
    int res = 0, unknown = 0;
    cin >> x;
    n = x.length();
    priority_queue<int>useg;

    int lf = -1, temp = 0, segs = 0;
    for (int i = 0 ; i < n ; ++i){
        if (x[i] == '?'){
            if (!temp) lf = i;
            temp++;
        }
        if (x[i] != '?' || i == n - 1){
            if (lf == 0 || (i == n - 1 && x[i] == '?') || x[lf - 1] == x[i]){
                res += temp;
                segs++;
            }
            useg.push(temp);
            temp = 0;
        }
    }

    for (int i = 'A' ; i <= 'C' ; ++i){
        int subres = Find(i);
        if (subres == 0){
            if (segs == 0)
                subres = useg.top();
            else segs--;
        }
        res += subres;
    }
        
    return res;
}

int main(){
    int T_T;
    scanf("%d", &T_T);
    while(T_T--) printf("%d\n", Solve());
}