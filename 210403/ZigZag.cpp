#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, K;
vector<string>dic[26];
int pos[26];

int main(){
    cin >> N >> K;
    for (int i = 0 ; i < N ; ++i){
        string temp;
        cin >> temp;
        dic[temp[0]- 'a'].push_back(temp);
    }
    for (int i = 0 ; i < 26 ; ++i)
        sort(dic[i].begin(), dic[i].end());
    for (int i = 0 ; i < K ; ++i){
        string temp;
        cin >> temp;
        int ind = temp[0] - 'a';
        cout << dic[ind][pos[ind]] << endl;
        pos[ind] = (pos[ind] + 1) % (dic[ind].size()); 
    }
    return 0;
}