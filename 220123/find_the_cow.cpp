#include <iostream>
#include <fstream>
using namespace std;
int left_pointer=0;
int left_positions[50005];
int right_pointer=0;
int right_positions[50005];
int main(){
    //在后面的左括号不可以和前面的右括号配对
    ifstream fin("cowfind.in");
    ofstream fout("cowfind.out");
    string line;
    fin>>line;
    for (int i=0; i<line.size()-1; i++) {
        if (line[i] == '(' && line[i+1] == '(') {
            left_positions[left_pointer] = i;
            left_pointer++;
        }
        else if(line[i] == ')' && line[i+1] == ')'){
            right_positions[right_pointer] = i;
            right_pointer++;
        }
    }
    long ans=0;
    for (int i=0; i<left_pointer; i++) {
        for (int j=0; j<right_pointer; j++) {
            if (right_positions[j] > left_positions[i]) {
                ans+=right_pointer-j;
                break;
            }
        }
    }

    fout<<ans<<endl;
    
    
    return 0;
}
