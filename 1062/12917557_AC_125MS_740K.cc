#include <iostream>
#include <cstring>
using namespace std;
struct goods
{
    int price;
    int level;
};
int m,n,low,high,dfs[100],graph[100][100];
bool judge[100];
goods g[100];
int DFS(int x)
{
    int min=g[x].price;
    judge[x]=1;
    for(int i=0;i!=n;++i)
    {
        if(judge[i]) continue;
        if(i!=x&&graph[x][i]!=-1&&g[i].level>=low&&high>=g[i].level)
        {
            int temp=graph[x][i]+DFS(i);
            judge[i]=0;
            if(min>temp){
                min=temp;
            }
        }
    }
    return min;
}
int main()
{
    memset(graph,-1,sizeof(graph));
    memset(dfs,-1,sizeof(dfs));
    cin>>m>>n;//等级差距,物品数
    for(int i=0;i!=n;++i)
    {
        int p,l,x;//价格\主人的地位等级和替代品总数
        cin>>p>>l>>x;
        for(int j=0;j!=x;++j)
        {
            int t,v;
            cin>>t>>v;//替代品的编号和"优惠价格"
            graph[i][t-1]=v;
        }
        g[i].price=p;
        g[i].level=l;
    }
    int answer[m+1];
    for(int i=-m;i!=1;++i)
    {
        memset(judge,0,sizeof(judge));
        low=g[0].level+i;
        high=g[0].level+i+m;
        answer[m+i]=DFS(0);
    }
    int min=answer[0];
    for(int i=1;i!=m+1;++i)
        if(answer[i]<min) min=answer[i];
    cout<<min<<endl;
    return 0;
}