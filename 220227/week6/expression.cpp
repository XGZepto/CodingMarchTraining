#include <iostream>
using namespace std;
long long numbers[100005];
int number_counter=0;
int main(){
    string line;
    cin>>line;
    long long s_size = line.size();
    for (int i = 0; i < s_size; i++)
    {
        if (line[i]!='+' && line[i]!='*')
        {
            int temp = i;
            while (line[temp]!='+' && line[temp]!='*' && temp<s_size)
            {
                temp++;
            }
            numbers[number_counter]  = stoll(line.substr(i,temp-i)); 
            number_counter++;
            i = temp-1;
        }
        else if (line[i]=='+')
        {
            continue;
        }
        else{
            //去找到下一个数，和前一个数乘一下
            long long number=0;
            int temp = i+1;
            while (line[temp]!='+' && line[temp]!='*' && temp<s_size)
            {
                temp++;
            }
            number = stoll(line.substr(i+1,temp-i-1));
            numbers[number_counter-1] = (numbers[number_counter-1]%10000)*(number%10000);
            i = temp-1;
        }
    }
    long long ans=0;
    for (int i = 0; i < number_counter; i++)
    {
        ans = ans + numbers[i];
        ans %= 10000;
    }
    cout<<ans<<endl;

    return 0;
}