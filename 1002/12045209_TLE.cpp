#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
using namespace std;
int main()
{
    vector<string> a;
    map<string,int> imap;
    int c,e=0;
    string d;
    cin>>c;
    vector<int> b1(c,0),b2(c,1);
    for(int i=0;i!=c;++i)
    {
        cin>>d;
        a.push_back(d);
    }
    for(int i=0;i!=c;++i)
    {
        string::iterator iter=a[i].begin();
        string::iterator endd=a[i].end();
        while(iter!=endd)
        {
            if(*iter=='-'){
                iter=a[i].erase(iter);
                endd=a[i].end();
            }
            else if(isupper(*iter))
            {
                 switch(*iter)
                {
            case'A':
            case'B':
            case'C':*iter='2';break;
            case'D':
            case'E':
            case'F':*iter='3';break;
            case'G':
            case'H':
            case'I':*iter='4';break;
            case'J':
            case'K':
            case'L':*iter='5';break;
            case'M':
            case'N':
            case'O':*iter='6';break;
            case'P':
            case'R':
            case'S':*iter='7';break;
            case'T':
            case'U':
            case'V':*iter='8';break;
            case'W':
            case'X':
            case'Y':*iter='9';break;
            default:break;
                 }
            ++iter;
            }
            else if(*iter>='0'&&*iter<='9')
                ++iter;
            else{}

        }
    }
    for(int i=0;i!=c;++i)
    {
        for(int j=i+1;j!=c;++j)
        {
            if(b1[j]==0)
            {
                if(a[i]==a[j])
                {
                    ++b2[i];
                    b1[j]=1;
                }
            }
        }
    }
    for(int i=0;i!=c;++i)
    {
        a[i].insert(a[i].begin()+3,'-');
        if(b2[i]!=1){
            e=2;
            imap.insert(make_pair(a[i],b2[i]));
        }
    }
    for(map<string,int>::iterator it=imap.begin();it!=imap.end();++it)
        cout<<(*it).first<<" "<<(*it).second<<endl;
    if(e==0)
        cout<<"No duplicates.";
    return 0;
}