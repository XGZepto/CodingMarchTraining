#include <iostream>
using namespace std;
int char2int(char num){
    return int(num) - '0';
}
char int2char(int num){
    return char(num + int('0'));
}
void digit_multiplication(char digit1,char digit2,char last_pass,char* pass,char* current){
    int result = char2int(digit1) * char2int(digit2) + char2int(last_pass);
    *current = int2char(result%10);
    if (result/10!=0) {
        //有进位
        *pass = int2char(result/10);
    }
    else{
        *pass = '0';
    }
}
void digit_addition(char digit1,char digit2,char last_pass,char* pass,char*current){
    int result = char2int(digit1) + char2int(digit2) + char2int(last_pass);
    *current = int2char(result%10);
    if (result>=10) {
        *pass = '1';
    }
    else{
        *pass = '0';
    }
}

string string_addition(string a,string b){
    string result="";
    if (a.size()<b.size()) {
        swap(a, b);
    }
    int a_size = a.size();
    int b_size = b.size();
    //将b的长度也拉这么长
    for (int i=0; i<a_size-b_size; i++) {
        b = '0'+b;
    }
    char last_pass = '0';
    for (int i=a_size-1; i>=0; i--) {
        if (i==a_size-1) {
            last_pass = '0';
        }
        char current,pass;
        digit_addition(a[i], b[i], last_pass, &pass, &current);
        last_pass = pass;
        result = current + result;
        if (i==0) {
            if (pass!='0') {
                result = pass + result;
            }
        }
    }
    return result;
}
string multiplication(string a,string b){
    string result = "0";
    int a_size = a.size();
    int b_size = b.size();
    string temp;
    char last_pass='0';
    int times_counter = 0;
    if (a.size()<b.size()) {
        swap(a, b);
    }
    //  666
    //   23
    //15318
    for (int i=b_size-1; i>=0; i--) {
        temp = "";
        for (int j=a_size-1; j>=0; j--) {
            char pass,current;
            if (j==a_size-1) {
                last_pass = '0';
            }
            digit_multiplication(a[j], b[i],last_pass,&pass,&current);
            last_pass = pass;
            temp = current + temp;
            //最后一位的特判
            if (j == 0) {
                if (pass!='0') {
                    temp = pass + temp;
                }
            }
        }
        //temp是每一轮乘出来的结果
        for (int j=0; j<times_counter; j++) {
            temp = temp+'0';
        }
        result = string_addition(temp, result);
        times_counter++;
    }
    return result;
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<multiplication(a, b)<<endl;
//    cout<<string_addition("0", "6")<<endl;
    return 0;
}
