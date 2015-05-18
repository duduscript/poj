#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    vector<string> a;
    int c,e=0;
    string d;
    cin>>c;
    vector<int> b1(c,0),b2(c,1);
    for(int i=0;i!=c;++i)
    {
        cin>>d;
        a.push_back(d);
        cin.clear();
    }
    for(int i=0;i!=c;++i)
    {
        string::iterator beg=a[i].begin();
        string::iterator endd=a[i].end();
        while(beg!=endd)
        {
            if(*beg=='-')
                beg=a[i].erase(beg);
            else if(islower(*beg))
                *beg=*beg-32;

            else if(isupper(*beg))
            {
                 switch(*beg)
                {
            case'A':
            case'B':
            case'C':*beg='2';break;
            case'D':
            case'E':
            case'F':*beg='3';break;
            case'G':
            case'H':
            case'I':*beg='4';break;
            case'J':
            case'K':
            case'L':*beg='5';break;
            case'M':
            case'N':
            case'O':*beg='6';break;
            case'P':
            case'R':
            case'S':*beg='7';break;
            case'T':
            case'U':
            case'V':*beg='8';break;
            case'W':
            case'X':
            case'Y':*beg='9';break;
            default:e=1;break;
                 }
            ++beg;
            }
            else if(*beg>='0'&&*beg<='9')
                ++beg;
            else{
                e=1;
                break;
            }
        }

    }
    if(e==1){
        cout<<"error inout!";
         return 0;
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
            cout<<a[i]<<"  "<<b2[i]<<endl;
        }
    }
    if(e==0)
        cout<<"No duplicates. ";
    return 0;
}