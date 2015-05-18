#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N=26;
bool situation[N],graph[N][N];
string sort;
int n,m;
int topo() {
    int situaionNum = 0,indegree[N];
    for(int i=0;i!=N;++i){
        if (situation[i]) situaionNum++;
    }
    memset(indegree,0,sizeof(indegree));
    for(int i=0;i!=N;++i){
        if (!situation[i]) continue;
        for(int j=0;j!=N;++j){
            if(graph[i][j]) ++indegree[j];
        }
    }
    queue<int> iqueue;
    bool judge[N];
    memset(judge,0,sizeof(judge));
    for(int i=0;i!=N;++i){
        if(situation[i] && !indegree[i] && !judge[i]){
            iqueue.push(i);
            judge[i]=1;
        }
    }
    bool sign = false;
    int sum=0;
    while(iqueue.size()){
        if(iqueue.size() > 1) sign = true;
        int t=iqueue.front();
        sort+='A'+t;
        iqueue.pop();
        sum++;
        for(int i=0;i!=N;++i){
            if(i==t) continue;
            if(!judge[i] && graph[t][i] && --indegree[i] == 0){
                iqueue.push(i);
                judge[i] = 1;
            }
        }
    }
    if(sum != situaionNum) return 1;
    if(sort.size()==n && !sign) return 0;
    return 2;
}
int main()
{
    while(cin>>n>>m){
        if(n==0 && m==0) break;
        memset(situation,0,sizeof(situation));
        memset(graph,0,sizeof(graph));
        string temp;
        int ans,sure=1;
        vector<string> get;
        for(int i=0;i!=m;++i){
            cin>>temp;
            get.push_back(temp);
        }
        for(int i=0;i!=m;++i,++sure){
            sort.clear();
            situation[get[i][0] - 'A'] = 1;
            situation[get[i][2] - 'A'] = 1;
            graph[get[i][0]-'A'][get[i][2]-'A']=1;
            ans=topo();
            if(ans == 0 || ans == 1) break;
        }
        if(ans==0)    cout<<"Sorted sequence determined after "<<sure<<" relations: "<<sort<<"."<<endl;
        else if(ans==1)    cout<<"Inconsistency found after "<<sure<<" relations."<<endl;
        else    cout<<"Sorted sequence cannot be determined."<<endl;
    }
    return 0;
}
