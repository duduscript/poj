#include <iostream>
#include <string>
using namespace std;
int c[101][101],d[101][101];
bool b[101][101];
int line,row;
string judge(int a,int b)
{
    string s(4,'1');
    if(a==1) s[0]='0';
    if(b==row) s[1]='0';
    if(a==line) s[2]='0';
    if(b==1) s[3]='0';
    return s;
}
int fun(int x,int y)
{
    string s=judge(x,y);
    int max=0;
    if(s[0]=='1'&&d[x][y]>d[x-1][y])
    {
        if(b[x-1][y]==0)
        {
            c[x-1][y]=fun(x-1,y);
            b[x-1][y]=1;
        }
        if(max<c[x-1][y])
            max=c[x-1][y];
    }
    if(s[1]=='1'&&d[x][y]>d[x][y+1])
    {
        if(b[x][y+1]==0)
        {
            c[x][y+1]=fun(x,y+1);
            b[x][y+1]=1;
        }
        if(max<c[x][y+1])
            max=c[x][y+1];
    }
    if(s[2]=='1'&&d[x][y]>d[x+1][y])
    {
        if(b[x+1][y]==0)
        {
            c[x+1][y]=fun(x+1,y);
            b[x+1][y]=1;
        }
        if(max<c[x+1][y])
            max=c[x+1][y];
    }
    if(s[3]=='1'&&d[x][y]>d[x][y-1])
    {
        if(b[x][y-1]==0)
        {
            c[x][y-1]=fun(x,y-1);
            b[x][y-1]=1;
        }
        if(max<c[x][y-1])
            max=c[x][y-1];
    }
    return max+1;
}

int main()
{
    line=row=0;
    cin>>line>>row;
    for(int i=1;i!=line+1;++i)
        for(int j=1;j!=row+1;++j)
        {
            c[i][j]=b[i][j]=0;
            cin>>d[i][j];
        }
    for(int i=1;i!=line+1;++i)
        for(int j=1;j!=row+1;++j)
        {
            if(b[i][j])
                continue;
            else
            {
                c[i][j]=fun(i,j);
                b[i][j]=1;
            }
        }
    int max=0;
    for(int i=1;i!=line+1;++i)
        for(int j=1;j!=row+1;++j)
            if(c[i][j]>max)
                max=c[i][j];
    cout<<max;
    return 0;
}
