#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<float> a;
    float c,su=0.0;
    int b=0;
    while(cin>>c&&c!=0.0)
        a.push_back(c);
    cout<<endl;
    for(size_t i=0;i!=a.size();++i)
        if(a[i]<0.01||a[i]>5.20)
        {
            cout<<"ERROR INPUT!";
            return 0;
        }
    for(size_t i=0;i!=a.size();++i)
    {
        for(int j=2;su<a[i];++j)
        {
                b=j;
                su+=(float)1/j;
        }
        cout<<b-1<<" card(s)"<<endl;
        b=0;
        su=0.0;
    }
    return 0;
}