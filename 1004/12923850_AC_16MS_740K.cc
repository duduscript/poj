#include<iostream>
using namespace std;
int main()
{
float a,sum=0;
for(int i=0;i!=12;++i)
{ cin>>a;
  sum+=a;
}
cout<<"$"<<sum/12.0<<endl;
return 0;
}
