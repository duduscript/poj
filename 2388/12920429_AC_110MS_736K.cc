#include <iostream>
using namespace std;
int n,cow[10001];
int fun(int low,int high)
{
    int temp=low;
    for(int i=low;i!=high;++i)
    {
        if(cow[i]<=cow[high])
        {
            cow[0]=cow[i];
            cow[i]=cow[temp];
            cow[temp++]=cow[0];
        }
    }
    cow[0]=cow[temp];
    cow[temp]=cow[high];
    cow[high]=cow[0];
    return temp;
}
void QuickSort(int low,int high)
{
    if(low<high)
    {
        int q=fun(low,high);
        if(q>n/2+1) QuickSort(low,q-1);
        else if(q<n/2+1) QuickSort(q+1,high);
        else return;
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>cow[i];
    QuickSort(1,n);
    cout<<cow[n/2+1]<<endl;
    return 0;
}