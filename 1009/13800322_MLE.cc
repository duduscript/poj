#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int length,sum;
bool b[8];
void fun_one(int number)
{
    memset(b,1,sizeof(b));
    if(number<length) { b[0]=0; b[4]=0; b[7]=0;}
    if((number+1)%length==0) { b[1]=0; b[4]=0; b[5]=0;}
    if(number>sum-length-1) { b[2]=0; b[5]=0; b[6]=0;}
    if(number%length==0) { b[3]=0; b[6]=0; b[7]=0;}
}
struct valnum{
    short value;
    int number;
    valnum(short _value,int _number):
        value(_value),number(_number){}
};
struct hind{
    short value;
    int number;
    size_t n;
    hind(short _value,int _number,size_t _n):
        value(_value),number(_number),n(_n){}
};
int abs(short x){
    return x>0?x:-x;
}
int main()
{
    while(cin>>length&&length)
    {
        cout<<length<<endl;
        short value;
        int number;
        vector<valnum> foo;
        queue<hind> sign;
        int threeLength = 3*length;
        sum = 0;
        int time = 0,num;
        while(cin>>value>>number&&(value!=0||number!=0)){
            ++time; num = number;
            if(number>threeLength){
                sign.push(hind(0,number-threeLength,foo.size()+length));
                number = threeLength;
            }
            for(int i=0;i!=number;++i)
                foo.push_back(valnum(value,sum++));
        }
        if(time == 1){
            cout<<0<<" "<<num<<endl;
            continue;
        }
        queue<valnum> ans;
        for(size_t i=0;i!=foo.size();++i){
            if(!sign.empty() && sign.front().n == i){
                ans.push(valnum(sign.front().value,sign.front().number));
                sign.pop();
            }
            short max = 0;
            fun_one(foo[i].number);
            if(b[0] && abs(foo[i].value - foo[i-length].value)>max)
                 max = abs(foo[i].value - foo[i-length].value);
            if(b[1] && abs(foo[i].value - foo[i+1].value)>max)
                 max = abs(foo[i].value - foo[i+1].value);
            if(b[2] && abs(foo[i].value - foo[i+length].value)>max)
                 max = abs(foo[i].value - foo[i+length].value);
            if(b[3] && abs(foo[i].value - foo[i-1].value)>max)
                 max = abs(foo[i].value - foo[i-1].value);
            if(b[4] && abs(foo[i].value - foo[i+1-length].value)>max)
                 max = abs(foo[i].value - foo[i+1-length].value);
            if(b[5] && abs(foo[i].value - foo[i+1+length].value)>max)
                 max = abs(foo[i].value - foo[i+1+length].value);
            if(b[6] && abs(foo[i].value - foo[i-1+length].value)>max)
                 max = abs(foo[i].value - foo[i-1+length].value);
            if(b[7] && abs(foo[i].value - foo[i-1-length].value)>max)
                 max = abs(foo[i].value - foo[i-1-length].value);
            ans.push(valnum(max,1));
        }
        ans.push(valnum(-1,-1));
        short tmpValue = ans.front().value;
        int tmpNum  = ans.front().number;
        ans.pop();
        while(!ans.empty()){
            if(ans.front().value == tmpValue){
                tmpNum += ans.front().number;
            }else{
                cout<<tmpValue<<" "<<tmpNum<<endl;
                tmpValue = ans.front().value;
                tmpNum   = ans.front().number;
            }
            ans.pop();
        }
        cout<<0<<" "<<0<<endl;
    }
    cout<<0<<endl;
    return 0;
}
