#include<iostream>
#include<vector>
using namespace std;
int fun(int,int,int,int);
int main()
{
    int a,b,c,d,e;
    vector<int> f;
    while(cin>>a>>b>>c>>d&&a!=-1&&b!=-1&&c!=-1&&d!=-1)
    {
    e=fun(a,b,c,d);
    f.push_back(e);
    }
    for(vector<int>::size_type i=0;i!=f.size();++i)
    {
        cout<<"Case "<<i+1<<": the next triple peak occurs in "<<f[i]<<" days.";
        cout<<endl;
    }
    return 0;
}
int fun(int a,int b,int c,int d)
{
    int aa,bb,cc;
    aa=a%23;
    bb=b%28;
    cc=c%33;
    for(int i=1;;i++)
    {
        if((i+d)%23==aa)
        {
            if((i+d)%28==bb)
            {
                if((i+d)%33==cc)
                    return i;
            }
        }
    }
}
