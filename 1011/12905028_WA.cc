#include <iostream>
#include <cstring>
#include <cmath>
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
            {
                while(judge[index+1]) index++;
                return DFS(divisor,index+1,n);
            }
        }
        else if(sticks[index]==divisor)
        {
            judge[index]=1;
            return 1;
        }
        else
        {
            while(sticks[index]==sticks[index+1]) index++;
            return DFS(divisor,index+1,n);
        }
    }
    return 0;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int chushu[64];
        memset(chushu,0,64);
        int sum=0,divisor=0,geshu=0;
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
        memset(judge,0,65);
        for(int i=1;i<=sqrt(sum);++i)
            if(sum%i==0)
            {
                if(sum/i>=sticks[0]) chushu[geshu++]=sum/i;
                if(i>=sticks[0]) chushu[geshu++]=i;
            }
        for(int i=0;i!=geshu-1;++i)
            for(int temp,j=0;j!=geshu-i-1;++j)
                if(chushu[j]>chushu[j+1])
                {
                    temp=chushu[j];
                    chushu[j]=chushu[j+1];
                    chushu[j+1]=temp;
                }
        divisor=chushu[0];
        int dijige=0;
        bool OK=1;
        while(OK)
        {
            memset(judge,0,n);
            for(int i=0;i!=n;++i)
            {
                if(!judge[i])
                {
                    if(DFS(divisor,i,n))
                        continue;
                    else
                    {
                        divisor=chushu[++dijige];
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