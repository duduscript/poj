#include <iostream>
#include <cstring>
using namespace std;
int sticks[65];
bool judge[65];
bool DFS(int divisor,int index,int n)
{
    if(judge[index])
        return DFS(divisor,index+1,n);
    if(index<n)
    {
        if(sticks[index]<divisor)
        {
            if(DFS(divisor-sticks[index],index+1,n))
            {
                judge[index]=1;
                return 1;
            }
            else
                return DFS(divisor,index+1,n);
        }
        else if(sticks[index]==divisor)
        {
            judge[index]=1;
            return 1;
        }
        else
            return DFS(divisor,index+1,n);
    }
    return 0;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int sum=0,divisor=0;
        for(int i=0;i!=n;++i)
        {
            cin>>sticks[i];
            sum+=sticks[i];
        }
        for(int i=0;i!=n-1;++i)
            for(int temp,j=0;j!=n-i-1;++j)
                if(sticks[j]<sticks[j+1])
                {
                    temp=sticks[j];
                    sticks[j]=sticks[j+1];
                    sticks[j+1]=temp;
                }
        memset(judge,65,0);
        divisor=sticks[0];
        while(sum%divisor) ++divisor;
        bool OK=1;
        while(OK)
        {
            memset(judge,n,0);
            for(int i=0;i!=n;++i)
            {
                if(!judge[i])
                {
                    if(DFS(divisor,i,n))
                        continue;
                    else
                    {
                        ++divisor;
                        while(sum%divisor!=0) ++divisor;
                        break;
                    }
                }
            }
            OK=0;
            for(int i=0;i!=n;++i)
                if(!sticks[i])
                {
                    OK=1;
                    break;
                }
        }
        cout<<divisor<<endl;
    }
    return 0;
}