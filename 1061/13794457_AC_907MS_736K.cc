#include <iostream>
#include <stdint.h>
using namespace std;
int main()
{
    int64_t x,y,m,n,L,D;
    cin>>x>>y>>m>>n>>L;
    int v = n -m;
    if(v>0) D = (x-y+L)%L;
    else{
        D = L-(x-y+L)%L;
        v = -v;
    }
    for(int i=0;i!=v;++i){
        if((i*L+D)%v == 0){
            cout<<(i*L+D)/v<<endl;
            return 0;
        }
    }
    cout<<"Impossible"<<endl;
    return 0;
}
