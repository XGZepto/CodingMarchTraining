#include <iostream>
using namespace std;
int numbers[100005];
int sorted_numbers[100005];
int number_pointer;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>numbers[i];
    }
    int left=0,right = n-1;
    while (left<=right)
    {
        if (abs(numbers[left])>abs(numbers[right]))
        {
            sorted_numbers[number_pointer] = numbers[left]*numbers[left];
            left++;
        }
        else{
            sorted_numbers[number_pointer] = numbers[right]*numbers[right];
            right--;
        }
        number_pointer++;
    }
    for (int i = number_pointer-1; i >=0; i--)
    {
        cout<<sorted_numbers[i]<<" ";
    }
    cout<<endl;

    return 0;
}