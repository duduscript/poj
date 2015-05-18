#include <iostream>
#include <vector>
using namespace std;
int tableGetToN[4] = {9, 189, 2889, 38889};
int tableGetAll[4] = {45, 9045, 1395495, 189414495};
int ten_exp(int n){
    int tmp = 1;
    for(int i=0;i!=n;++i,tmp*=10);
    return tmp;
}
int getLength(int n){
    int tmp = 10,length =1;
    while(n/tmp != 0){
        length += 1;
        tmp *= 10;
    }
    return length;
}
int getToN(int n){
    int lengthOfN = getLength(n);
    if(lengthOfN == 1) return n;
    return tableGetToN[lengthOfN-2]+(n+1-ten_exp(lengthOfN-1))*lengthOfN;
}
int getAll(int n){
    int lengthOfN = getLength(n);
    if(lengthOfN == 1) return n*(n+1)/2;
    int length = tableGetAll[lengthOfN - 2];
    int num = n+1-ten_exp(lengthOfN -1);
    length += num*(tableGetToN[lengthOfN-2])+num*(num+1)/2*lengthOfN;
    return length;
}
int getN(int n){
    int i=1;
    for(;n>getAll(i);++i);
    return i-1;
}
int getNumpo(int i,int n){
    for(;i!=1;--i){
        n /= 10;
    }
    return n%10;
}
int getNumber(int n){
    int i=0,tmp = n;
    while(tmp>0){
        tmp -= getLength(++i);
    }
    n = tmp+getLength(i);
    return getNumpo(n,i);
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