#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n,k,time;
void DFS(bool** area,int x,int y,int number)
{
    if(number==k)
    {
        ++time;
    }
    else
    {
        bool temp_row[n],temp_line[n];
        memset(temp_row,0,sizeof(temp_row));
        memset(temp_line,0,sizeof(temp_line));
        for(int i=0;i!=n;++i)
        {
            if(area[i][y])
            {
                area[i][y]=0;
                temp_row[i]=1;
            }
            if(area[x][i])
            {
                area[x][i]=0;
                temp_line[i]=1;
            }
        }
        for(int i=x+1;i!=n;++i)
            for(int j=0;j!=n;++j)
                if(area[i][j])
                    DFS(area,i,j,number+1);
        for(int i=0;i!=n;++i)
        {
            if(temp_row[i])
                area[i][y]=1;
            if(temp_line[i])
                area[x][i]=1;
        }
    }
}
int main()
{
    while(cin>>n>>k&&(n!=-1&&k!=-1))
    {
        bool** area;
        area=new bool*[n];
        for(int i=0;i!=n;++i)
            area[i]=new bool[n];
        for(int i=0;i!=n;++i)
            for(int j=0;j!=n;++j)
                area[i][j]=0;
        time=0;
        string line;
        for(int i=0;i!=n;++i)
        {
            cin>>line;
            for(int j=0;j!=n;++j)
                if(line[j]=='#')
                    area[i][j]=1;
        }
        for(int i=0;i!=n-k+1;++i)
            for(int j=0;j!=n;++j)
                if(area[i][j])
                    DFS(area,i,j,1);
        cout<<time;
        for(int i=0;i!=n;++i)
            delete[] area[i];
        delete[] area;
    }
    return 0;
}