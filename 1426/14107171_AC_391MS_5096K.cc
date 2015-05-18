#include <iostream>
#include <queue>
using namespace std;
void dfs(int input){
    queue<long long> q;
    bool sign = input%2;
    q.push(1);
    while(true){
        long long tmp = q.front();
        q.pop();
        q.push(tmp*10);
        q.push(tmp*10 + 1);
        if(tmp&(long long)1 != sign) continue;
        if(tmp%input == 0){
            cout<<tmp<<endl;
            return;
        }
    }
}
int main()
{
    queue<int> input;
    int inputTemp;
    while(cin>>inputTemp&&inputTemp != 0){
        input.push(inputTemp);
    }
    while(!input.empty()){
        dfs(input.front());
        input.pop();
    }
    return 0;
}
