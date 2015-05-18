#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
int n,sum,divisor,sticks[65];
bool judge[65];
struct fuck{
    bool operator()(const int& a,const int& b){
        return a>=b;
    }
};
bool dfs(int length ,int index,int cn){
	if(cn * divisor == sum) return true;
	for(int i=index;i!=n;++i){
		if(judge[i]||(i&&!judge[i]&&sticks[i]==sticks[i-1]))
			continue; 
		if(length+sticks[i]==divisor){
			judge[i] = true;
			if(dfs(0,0,cn+1)) return true;
			judge[i] = false;
			return false;
		} else if(length+sticks[i] < divisor){
			judge[i] = true;
			if(dfs(length+sticks[i],i+1,cn)) return true;
			judge[i] = false;
			if(length == 0) return false;
		}	
	}
    return false;
}
int main(){
    ifstream in("test.txt");
    while(in>>n&&n){
		sum = 0;
        for(int i=0;i!=n;++i){
            in>>sticks[i];
            sum+=sticks[i];
        }
        sort(sticks,sticks+n,fuck());
        for(divisor=sticks[0];divisor!=sum+1;++divisor){
            if(sum%divisor) continue;
			memset(judge,0,sizeof(judge));
			if(dfs(0,0,0)) break;
		}
        cout<<divisor<<endl;
    }
    return 0;
}