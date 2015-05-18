#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==0)
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
    vector<int> ik_left(n,0),ik_right(n,0);
    ik_left[n-1]=0;
    for(int i=n-2;i!=-1;--i)
    {
        bool judge=0,can=1;
        int max=0;
        for(int j=n-1;j!=i;--j)
            if(ivec[j]<=ivec[i]&&ik_left[j]>=max)
            {
                if(ivec[j]==ivec[i]&&can)
                    can=0;
                else if(ivec[j]==ivec[i]&&!can)
                    continue;
                max=ik_left[j];
                judge=1;
            }
        if(judge)
            ik_left[i]=max+1;
    }
    ik_right[0]=0;
    for(int i=1;i!=n;++i)
    {
        bool judge=0,can=1;
        int max=0;
        for(int j=0;j!=i;++j)
            if(ivec[j]<=ivec[i]&&ik_right[j]>=max)
            {
                if(ivec[i]==ivec[j]&&can)
                    can=0;
                else if(ivec[i]==ivec[j]&&!can)
                    continue;
                max=ik_right[j];
                judge=1;
            }
        if(judge)
            ik_right[i]=max+1;
    }
    int max=0;
    for(int i=0;i!=n;++i)
        if(ik_left[i]+ik_right[i]>max)
            max=ik_left[i]+ik_right[i];
    max++;
    cout<<n-max;
    return 0;
}
