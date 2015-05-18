#include <iostream>
#include <vector>
using namespace std;
int fun(int n,vector<int> sslist){
    vector<int> slist;
    for(int i=n;;++i){
        if((i+1)%(n+1)!=0&&(i+1)%(n+1)!=1) continue;
        if((i+1)%(2*n)<=n&&(i+1)%(2*n)!=0) continue;
        slist=sslist;
        vector<int>::iterator it = slist.begin();
        int l,j=0;
        for(;j!=n;++j){
            l=i%(2*n-j);
            if(it+l>=slist.end())
                it=it+l-(2*n-j);
            else
                it+=l;
            if(*it!=1)
                break;
            slist.erase(slist.end()-1);
            if(it==slist.end())
                it=slist.begin();
        }
        if(j==n)
            return i+1;
    }
}
int main(){
    int n;
    while(cin>>n&&n!=0){
        vector<int> slist;
        for(int i=0;i!=n;++i)
            slist.push_back(0);
        for(int i=0;i!=n;++i)
            slist.push_back(1);
        int answer=fun(n,slist);
        cout<<answer<<endl;
    }
    return 0;
}