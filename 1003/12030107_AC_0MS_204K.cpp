#include<iostream>
using namespace std;
int main()
{
    int k;
    float s,sum;
    while(cin>>s&&s!=0.0)
    {
        sum=0.0;
        for(int i=2;sum<s;++i)
        {
            k=i-1;
            sum+=(float)1/i;
        }
        cout<<k<<" card(s)"<<endl;;
    }
    return 0;
}
