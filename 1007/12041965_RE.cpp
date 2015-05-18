#include<iostream>
#include<string>
#include<vector>
using namespace std;
int fun(int);
int main()
{
    int a,b,c;
    cin>>a>>b;
    c=fun(a);
    string is;
    vector<string> ivec;
    vector<int> inve1(b,0),inve2(b,0);
    for(int i=0;i!=b;++i)
    {
        cin>>is;
        ivec.push_back(is);
    }
    cout<<endl;
    string::iterator beg,iter;
    for(int i=0;i!=b;++i)
    {
        beg=ivec[i].begin();
        for(;beg!=ivec[i].end();++beg)
        {
             iter=beg+1;
             while(iter!=ivec[i].end())
            {
                if(*beg>*iter)
                       ++inve1[i];
                ++iter;
            }
        }
    }
    for(int pp,i=0,imin=c;i!=b;++i)
    {
        for(int j=0;j!=b;++j)
        {
            if(inve2[j]==0&&imin>inve1[j])
            {
                    pp=j;
                    imin=inve1[j];
            }
        }
        inve2[pp]=1;
        cout<<ivec[pp]<<endl;
        imin=c;
    }
    return 0;
}
int fun(int x)
{
    int m=0;
    for(int i=1;i!=x;++i)
        m+=i;
    return m;
}