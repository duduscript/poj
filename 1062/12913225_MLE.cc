#include <iostream>
#include <cstring>
using namespace std;
int graph[100][100];
struct goods
{
    int price;
    int level;
};
int m,n,dfs[100];
goods g[100];
int DFS(int x,int low,int high)
{
    int min=g[x].price;
    for(int i=0;i!=n;++i)
    {
        if(i!=x&&graph[x][i]!=-1&&g[i].level>=low&&high>=g[i].level)
        {
            int l=(low+high)/2>=g[i].level?low:g[i].level-m;
            int h=(low+high)/2>=g[i].level?g[i].level+m:high;
            int temp=graph[x][i]+DFS(i,l,h);
            if(min>temp)
                min=temp;
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
    for(int i=0;i!=n;++i)
        for(int j=0;j!=n;++j)
            if(graph[i][j]!=-1&&(g[i].level-g[j].level>m||g[j].level-g[i].level>m))
                graph[i][j]=-1;
    cout<<DFS(0,g[0].level-m,g[0].level+m);
    return 0;
}
