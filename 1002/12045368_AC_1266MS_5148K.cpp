#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
int main()
{
    map<string,int> imap;
    int c,e=0;
    string d;
    cin>>c;
    for(int i=0;i!=c;++i)
    {
        cin>>d;
        string::iterator iter=d.begin();
        string::iterator endd=d.end();
        while(iter!=endd)
        {
            if(*iter=='-'){
                iter=d.erase(iter);
                endd=d.end();
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
        d.insert(d.begin()+3,'-');
        ++imap[d];
    }
    for(map<string,int>::iterator it=imap.begin();it!=imap.end();++it)
    if((*it).second!=1){
        cout<<(*it).first<<" "<<(*it).second<<endl;
        e=1;
    }
    if(e==0)
        cout<<"No duplicates.";
    return 0;
}