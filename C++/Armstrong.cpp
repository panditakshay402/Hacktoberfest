#include <iostream>
using namespace std;

int countDigit(int num){
    int count =0;
    while(num!=0){
        num=num/10;
        count++;
    }
    return count;
}

bool isArmstrong(int num){
    int orgNum=num;
    int numDigit=countDigit(num);
    int sum = 0;
    while(num>0){
        int digit = num%10;
        int power=1;
        for (int i=0;i<numDigit;i++){
            power=power*digit;
        }
        sum = sum + power;
        num = num/10;
    }
    return sum == orgNum;
}

int main(){
    int num;
    cout << "enter num : ";
    cin >> num;
    if((isArmstrong(num))){
        cout << num << " is Armstrong Number" << endl;
    }
    else{
        cout << num << " is not Armstrong Number" << endl;
    }
    return 0;
}