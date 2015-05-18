#include <iostream>
#include <vector>
using namespace std;
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
        if(ivec[k]>v)
            return 0;
        else
            return ivec[k];
    }
    else
    {
        if(v-ivec[k]==0)
            return v;
        else if(v-ivec[k]<0)
        {
            return fun(k-1,v);
        }
        else
        {
            if(fun(k-1,v)>fun(k-1,v-ivec[k])+ivec[k])
            {
                return fun(k-1,v);
            }
            else
            {
                return fun(k-1,v-ivec[k])+ivec[k];
            }
        }
    }
}

int main()
{
    while(1)
    {
        ivec.clear();
        ivec.push_back(0);
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
        if(n==1)
            cout<<0<<endl;
        else
            cout<<fun(n,sum)<<endl;
    }
    return 0;
}