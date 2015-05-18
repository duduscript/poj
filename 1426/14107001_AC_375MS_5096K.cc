#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;
void dfs(int input){
    queue<long long> q;
    q.push(1);
    while(true){
        long long tmp = q.front();
        q.pop();
        if(tmp%input == 0){
            cout<<tmp<<endl;
            return;
        }
        q.push(tmp*10);
        q.push(tmp*10 + 1);
    }
}
int main()
{
    //fstream in("C:\\Qt\\Tools\\QtCreator\\bin\\FindTheMultiple\\test.txt");
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
