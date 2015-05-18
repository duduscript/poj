#include <iostream>
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
    int value,number;
    valnum(int _value,int _number):
        value(_value),number(_number){}
};
struct hind{
    int value,number; size_t n;
    hind(int _value,int _number,int _n):
        value(_value),number(_number),n(_n){}
};
int abs(int x){
    return x>0?x:-x;
}
int main()
{
    while(cin>>length&&length)
    {
        cout<<length<<endl;
        int value, number;
        vector<valnum> foo;
        vector<hind> sign;
        int threeLength = 3*length;
        sum = 0;
        while(cin>>value>>number&&(value!=0||number!=0)){
            if(number>threeLength){
                sign.push_back(hind(0,number-threeLength,foo.size()+length));
                number = threeLength;
            }
            for(int i=0;i!=number;++i)
                foo.push_back(valnum(value,sum++));
        }
        vector<valnum> ans;
        size_t index = 0;
        for(size_t i=0;i!=foo.size();++i){
            if(index<sign.size() && sign[index].n == i){
                ans.push_back(valnum(sign[index].value,sign[index].number));
                ++index;
            }
            int max = 0;
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
            ans.push_back(valnum(max,1));
        }
        ans.push_back(valnum(-1,-1));
        int tmpValue = ans[0].value;
        int tmpNum   = ans[0].number;
        for(size_t i=1;i!=ans.size();++i){
            if(ans[i].value == tmpValue){
                tmpNum += ans[i].number;
                continue;
            }else{
                cout<<tmpValue<<" "<<tmpNum<<endl;
                tmpValue = ans[i].value;
                tmpNum   = ans[i].number;
            }
        }
        cout<<0<<" "<<0<<endl;
    }
    cout<<0<<endl;
    return 0;
}
