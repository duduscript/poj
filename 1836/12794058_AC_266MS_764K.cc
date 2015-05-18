#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0||n==1||n==2)
    {
        cout<<0;
        return 0;
    }
    double temp;
    vector<double> ivec;
    for(int i=0;i!=n;++i)
    {
        cin>>temp;
        ivec.push_back(temp);
    }
    vector<int> ik_left(n,0),ik_right(n,0),ans(n,0);
    ik_left[n-1]=1;
    for(int i=n-2;i!=-1;--i)
    {
        int max=0;
        for(int j=n-1;j!=i;--j)
            if(ivec[j]<ivec[i]&&ik_left[j]>=max)
                max=ik_left[j];
        ik_left[i]=max+1;
    }
    ik_right[0]=1;
    for(int i=1;i!=n;++i)
    {
        int max=0;
        for(int j=0;j!=i;++j)
            if(ivec[j]<ivec[i]&&ik_right[j]>=max)
                max=ik_right[j];
         ik_right[i]=max+1;
    }
    for(int i=0;i!=n-1;++i)
    {
        int max=0;
        for(int j=i+1;j!=n;++j)
            if(max<ik_left[j]+ik_right[i])
                max=ik_left[j]+ik_right[i];
        ans[i]=max;
    }
    int max=0;
    for(int i=0;i!=n;++i)
        if(max<ans[i])
            max=ans[i];
    cout<<n-max;
    return 0;
}