#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool fun(double d,double a,double x,double y)
{
    return (x-a)*(x-a)+y*y-d*d<=0.0001;
}
int main()
{
    int n,number;
    double d;
    vector<double> ivec_x,ivec_y,ans;
    while(cin>>n>>d&&!(n==0&&d==0))
    {
        if(n==0)
        {
            ans.push_back(0);
            continue;
        }
        number=0;
        bool judge=1;
        double x,y;
        for(int i=0;i!=n;++i)
        {
            cin>>x>>y;
            if(y>d) judge=0;
            if(y<0) continue;
            ivec_x.push_back(x);
            ivec_y.push_back(y);
        }
        if(!judge)
        {
            ivec_x.clear();
            ivec_y.clear();
            ans.push_back(-1);
            continue;
        }
        vector<double> temp(n,0.0);
        for(int i=0;i!=n;++i)
            temp[i]=ivec_x[i]-sqrt(d*d-ivec_y[i]*ivec_y[i]);
        for(int i=0;i!=n-1;++i)
        {
            double temp_x,temp_y,t;
            for(int j=i+1;j!=n;++j)
                if(temp[i]>temp[j])
                {
                        t=temp[i];
                        temp[i]=temp[j];
                        temp[j]=t;
                        temp_x=ivec_x[i];
                        temp_y=ivec_y[i];
                        ivec_x[i]=ivec_x[j];
                        ivec_y[i]=ivec_y[j];
                        ivec_x[j]=temp_x;
                        ivec_y[j]=temp_y;
                }
        }
        int nn=ivec_x.size()-1;
        while(nn>=0)
        {
            double location=ivec_x[nn]-sqrt(d*d-ivec_y[nn]*ivec_y[nn]);
            bool de=1;
            while(de)
            {
                de=fun(d,location,ivec_x[nn],ivec_y[nn]);
                if(de) --nn;
                if(nn<0) break;
            }
            ++number;
        }
        ans.push_back(number);
        ivec_x.clear();
        ivec_y.clear();
    }
    for(size_t i=0;i!=ans.size();++i)
        cout<<"Case "<<i+1<<": "<<ans[i]<<endl;
    return 0;
}
