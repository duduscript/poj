#include <iostream>
#include <vector>
using namespace std;
int tableGetToN[] = {0,9, 189, 2889, 38889};
int tableGetAll[] = {0,45, 9045, 1395495, 189414495};
int ten_exp(int n){
    int tmp = 1;
    for(int i=0;i!=n;++i,tmp*=10);
    return tmp;
}
int getLength(int n){
    if(n<10) return 1;
    else if(n<100) return 2;
    else if(n<1000) return 3;
    else if(n<10000) return 4;
    else return 5;
}
int getToN(int n){
    int lengthOfN = getLength(n);
    return tableGetToN[lengthOfN-1]+(n+1-ten_exp(lengthOfN-1))*lengthOfN;
}
int getAll(int n){
    int lengthOfN = getLength(n);
    int length = tableGetAll[lengthOfN - 1];
    int num = n+1-ten_exp(lengthOfN -1);
    length += num*tableGetToN[lengthOfN-1]+num*(num+1)/2*lengthOfN;
    return length;
}
int getN(int n){
    int j=1,i=1;
    for(;i!=5;++i){
        if(n>tableGetAll[i]) j*=10;
        else break;
    }
    n -= tableGetAll[i-1];
    for(;n>0;++j){
        n -= getToN(j);
    }
    return j-2;
}
int getNumpo(int index,int n){
    index = getLength(n)-index+1;
    for(;index!=1;--index){
        n /= 10;
    }
    return n%10;
}
int getNumber(int n){
    int num=0,tmp = n;
    while(tmp>0){
        tmp -= getLength(++num);
    }
    n = tmp+getLength(num);
    return getNumpo(n,num);
}
int getResult(int n){
    int num = getN(n);
    return getNumber(n-getAll(num));
}
int main(){
    int N,n;
    cin>>N;
    vector<int> input;
    for(int i=0;i!=N;++i){
        cin>>n;
        input.push_back(n);
    }
    for(int i=0;i!=N;++i){
        cout<<getResult(input[i])<<endl;
    }
    return 0;
}