#include<iostream>
using namespace std;
struct child
{
    int num;
    child* next;
};
child* create(int);
void function(int);
int main()
{
    int in;
    while(cin>>in&&in!=0)
        function(in);
    return 0;
}
child* create(int a)
{
    child *head,*p;
    head=new child;
    p=head;
    for(int i=0;i!=a;++i){
        head->num=0;
        head->next=new child;
        head=head->next;
    }
    for(int i=0;i!=a-1;++i){
        head->num=1;
        head->next=new child;
        head=head->next;
    }
    head->num=1;
    head->next=p;
    return p;
}
void function(int a)
{
    child *p=create(a),*q=NULL;
    int out;
    for(int i=a+1,j=0;;++i,j=0,p=create(a)){
         if(i%(2*a)<=a&&i%(2*a)!=0) continue;
         for(;j!=a;++j){
             for(int k=0;k!=(i-1)%(2*a-j);++k){
                q=p;
                p=p->next;
             }
             if(p->num==0)  break;
             else{
                q->next=p->next;
                delete p;
                p=q->next;
             }}
         if(j==a){
            out=i;
            break;
         }}
    cout<<out<<endl;
}