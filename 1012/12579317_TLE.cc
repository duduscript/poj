#include <iostream>
#include <list>
using namespace std;
int fun(int n,list<int> sslist)
{
    list<int> slist;
    for(int i=n;;++i)
    {
        if((i+1)%(2*n)<=n&&(i+1)%(2*n)!=0) continue;
        slist=sslist;
        int j=0;
        list<int>::iterator it = slist.begin();
        int m=i,l;
        for(;j!=n;++j)
        {
            l=m%(2*n-j);
            for(int k=0;k!=l;++k)
            {
                ++it;
                if(it==slist.end())
                    it=slist.begin();
            }
            if(*it<=n)
                break;
            else
            {
                it=slist.erase(it);
                if(it==slist.end())
                    it=slist.begin();
            }
        }
        if(j==n)
        {
            slist.clear();
            return i+1;
        }
        else
            slist.clear();
    }
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        list<int> slist;
        for(int i=0;i!=2*n;++i)
        {
            slist.push_back(i+1);
        }
        int answer=fun(n,slist);
        cout<<answer<<endl;
    }
    return 0;
}