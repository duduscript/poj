#include <iostream>
using namespace std;
int main()
{
    long x,y,m,n,L,a,b;
    cin>>x>>y>>m>>n>>L;
    cout<<endl;
    a=x-y;
    b=m-n;
    for(int i=1;;++i){
        if((a+i*b)%L==0) {cout<<i; break;}
        if((a+i*b)%L==a) {cout<<"Impossible"; break;}
    }
    return 0;
}
