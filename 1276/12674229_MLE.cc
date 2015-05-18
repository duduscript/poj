#include <iostream>
#include <vector>
using namespace std;
int f[50][100001];
bool b[50][100001];
vector<int> ivec;
int fun_one(int a)
{
    if(a==0) return 0;
    int b=1;
    for(int i=1;;++i)
    {
        b*=2;
        if(a>=b-1&&a<2*b-1)
            return i;
    }
}
int fun(int k,int v)
{
    if(k==0) return 0;
    else if(k==1)
    {
        if(ivec[k-1]>v)
            return 0;
        else
            return ivec[k-1];
    }
    else
    {
        if(v-ivec[k-1]==0)
            return v;
        else if(v-ivec[k-1]<0)
        {
            if(b[k-1][v]==0)
            {
                f[k-1][v]=fun(k-1,v);
                b[k-1][v]=1;
            }
            return f[k-1][v];
        }
        else
        {
            if(b[k-1][v]==0)
            {
                f[k-1][v]=fun(k-1,v);
                b[k-1][v]=1;
            }
            if(b[k-1][v-ivec[k-1]]==0)
            {
                f[k-1][v-ivec[k-1]]=fun(k-1,v-ivec[k-1]);
                b[k-1][v-ivec[k-1]]=1;
            }
            if(f[k-1][v]>f[k-1][v-ivec[k-1]]+ivec[k-1])
            {
                return f[k-1][v];
            }
            else
            {
                return f[k-1][v-ivec[k-1]]+ivec[k-1];
            }
        }
    }
}

int main()
{
    while(1)
    {
        for(int i=0;i!=200;++i)
            for(int j=0;j!=100001;++j)
                f[i][j]=b[i][j]=0;
        ivec.clear();
        int sum,n;
        int number[11],value[11];
        cin>>sum>>n;
        for(int i=1;i!=n+1;++i)
            cin>>number[i]>>value[i];
        number[0]=value[0]=0;
        for(int i=1;i!=n+1;++i)
        {
            int k=1;
            if(fun_one(number[i]==0)) continue;
            for(int j=0;j!=fun_one(number[i]);++j)
            {
                ivec.push_back(k*value[i]);
                k*=2;
            }
            if(number[i]-k+1==0) continue;
            ivec.push_back((number[i]-k+1)*value[i]);
        }
        n=ivec.size();
        cout<<fun(n,sum)<<endl;
    }
    return 0;
}
