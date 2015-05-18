#include <iostream>
using namespace std;
int f[11][1001];
bool b[11][1001];
int fun(int k,int v,int* number,int* value)
{
    if(k==0) return 0;
    int max=0;
    for(int i=0;i!=*(number+k)+1;++i)
    {
        if(v-i*(*(value+k))<0)
            break;
        if(b[k-1][v-i*(*(value+k))]==0)
        {
            if(k==1)
            {
                return v%(*(value+1));
            }
            f[k-1][v-i*(*(value+k))]=
                    fun(k-1,v-i*(*(value+k)),number,value) + i*(*(value+k));
            b[k-1][v-i*(*(value+k))]=1;
        }
        if(f[k-1][v-i*(*(value+k))]>max)
        {
            max=f[k-1][v-i*(*(value+k))];
        }
    }
    return max;
}
int main()
{
    while(1)
    {
        for(int i=0;i!=11;++i)
            for(int j=0;j!=1001;++j)
            {
                f[i][j]=0;
                b[i][j]=0;
            }
        int n,sum,temp_a,temp_b;
        int number[1001],value[1001];
        cin>>sum>>n;
        for(int i=0;i!=n;++i)
        {
            cin>>temp_a>>temp_b;
            number[i+1]=temp_a;
            value[i+1]=temp_b;
        }
        number[0]=value[0]=0;
        f[n][sum]=fun(n,sum,number,value);
        cout<<f[n][sum]<<endl;
    }
    return 0;
}