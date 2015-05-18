#include <iostream>
#include <queue>
using namespace std;
void dfs(int input){
    queue<long long> q;
    q.push(1);
    while(true){
        long long tmp = q.front();
        if(tmp%input == 0){
            cout<<tmp<<endl;
            return;
        }
        long long tmp2 = tmp*10;
        q.push(tmp2);
        q.push(tmp2 + 1);
        q.pop();
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
