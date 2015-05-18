#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
int k;
bool judge[100001];
using namespace std;
int main()
{
    memset(judge, 0, sizeof(judge));
    int n;
    queue<pair<int, int> > Queue;
    cin >> n >> k;
    judge[n] = 1;
    Queue.push(make_pair(n,0));
    while(Queue.size())
    {
        pair<int,int> p=Queue.front();
        Queue.pop();
        if (p.first == k)
        {
            cout<<p.second<<endl;
            return 0;
        }
        else if (p.first < k&& p.first >= 0)
        {
            if (2 * p.first <= 100000 && !judge[2 * p.first])
            {
                Queue.push(make_pair(2 * p.first, p.second + 1));
                judge[2 * p.first] = 1;
            }
            if (p.first + 1<= 100000 && !judge[p.first + 1])
            {
                Queue.push(make_pair(p.first + 1, p.second + 1));
                judge[p.first + 1] = 1;
            }
        }
        if (p.first <= 100000 && p.first - 1>= 0 && !judge[p.first - 1])
        {
            Queue.push(make_pair(p.first - 1, p.second + 1));
            judge[p.first - 1] = 1;
        }
    }
}
