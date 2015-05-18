#include <iostream>
#include <vector>
using namespace std;

int a[1001],p[1001];
int c[101][101];
bool b[101][101];

int fun_a(int m,int n)
{
    int sum=0;
    for(int i=m;i!=n+1;++i)
        sum+=a[i];
    return (sum+10)*p[n];
}

int fun_s(int m,int n)
{
    int min;
    if(m!=n)
    {
        min=fun_a(m,n);
        for(int i=m;i!=n;++i)
        {
            if(b[m][i]==0)
            {
                c[m][i]=fun_s(m,i);
                b[m][i]=1;
            }
            if(b[i][n]==0)
            {
                c[i+1][n]=fun_s(i+1,n);
                b[i+1][n]=1;
            }
            if(min>c[m][i]+c[i+1][n])
                min=c[m][i]+c[i+1][n];
        }
    }
    else
    {
        min=(10+a[m])*p[m];
    }
    return min;
}

int main()
{
    int time;
    vector<int> an;
    cin>>time;
    while(time--)
    {
        for(int i=1;i!=1001;++i)
        {
            a[i]=p[i]=0;
        }
        for(int i=0;i!=101;++i)
            for(int j=0;j!=101;++j)
                b[i][j]=c[i][j]=0;
        int n;
        cin>>n;
        for(int i=1;i!=n+1;++i)
            cin>>a[i]>>p[i];
        c[1][n]=fun_s(1,n);
        an.push_back(c[1][n]);
    }
    for(size_t i=0;i!=an.size();++i)
        cout<<an[i]<<endl;
    return 0;
}