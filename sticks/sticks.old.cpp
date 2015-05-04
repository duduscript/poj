#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
int n,sticks[65],divisors[65];
bool judge[65];
struct fuck{
    bool operator()(const int& a,const int& b){
        return a>=b;
    }
};
bool DFS(int divisor,int index){
    if(judge[index])  return DFS(divisor,index+1);
    if(index<n){
        if(sticks[index]<divisor){
            if(DFS(divisor-sticks[index],index+1)){
                judge[index]=1;
                return 1;
            }else{
                while(judge[index+1]) index++;
                return DFS(divisor,index+1);
            }
        } else if(sticks[index]==divisor) {
            judge[index]=1;
            return 1;
        } else {
            while(sticks[index]>divisor) index++;
            if(index >= n) return 0;
            return DFS(divisor,index);
        }
    }
    return 0;
}
int main()
{
    ifstream in("test.txt");
    while(in>>n&&n){
        int sum=0,divisor=0,end_div=0;
        for(int i=0;i!=n;++i){
            in>>sticks[i];
            sum+=sticks[i];
        }
        sort(sticks,sticks+n,fuck());
        memset(divisors,0,sizeof(divisors));
        memset(judge,0,sizeof(judge));
        for(int i=sticks[0];i!=sum+1;++i){
            if(sum%i==0) divisors[end_div++] = i;
        }
        divisor=divisors[0];
        int index=0;
        while(true){
            memset(judge,0,sizeof(judge));
            for(int i=0;i!=n;++i){
				if(judge[i])
					continue;
                if(DFS(divisor,i))
                    continue;
                else{
                    divisor=divisors[++index];
					break;
				}
            }
			int index_i=0;
            for(;index_i!=n;++index_i)
                if(!judge[index_i])    break;
			if(index_i == n) break;
        }
        cout<<divisor<<endl;
    }
    return 0;
}
