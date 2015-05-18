#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool map[30][30];
int direction[8][2] = {{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};
vector<int> c,r;
int N,col,row;
bool dfs(int _col,int _row,int n){
    c.push_back(_col);
    r.push_back(_row);
    map[_col][_row] = 1;
    if (n == N) return true;
    int newCol,newRow;
    bool sign = false;
    for(int i=0;i!=8;++i){
        newCol = _col+direction[i][0];
        newRow = _row+direction[i][1];
        if( newCol>=0 && newCol<col && newRow>=0 && newRow<row
                && !map[newCol][newRow]
                && dfs(newCol,newRow,n+1)){
            sign = true;
            break;
        }
    }
    if (sign) return true;
    c.pop_back();
    r.pop_back();
    map[_col][_row] = 0;
    return false;
}
void printPath(int k,bool sign){
    cout<<"Scenario #"<<k<<":"<<endl;
    if(sign){
        char ch;
        for(size_t index=0;index != c.size();++index){
            ch = 'A' + c[index];
            cout<<ch<<r[index]+1;
        }
        cout<<endl;
    }else{
        cout<<"impossible"<<endl;
    }
}
int main()
{
    int time;
    cin>>time;
    vector<int> inputCol(time);
    vector<int> inputRow(time);
    for(int k=0;k!=time;++k)
        cin>>inputRow[k]>>inputCol[k];
    for(int k=0; k!=time; ++k){
        memset(map,0,sizeof(map));
        col = inputCol[k];
        row = inputRow[k];
        N = col*row;
        bool sign = false;
        vector<int>(0).swap(c);
        vector<int>(0).swap(r);
        for(int i=0;i<=col/2;++i){
            for(int j=0;j<=row/2;++j){
                if(dfs(i,j,1)){
                    printPath(k+1,true);
                    sign = true;
                    break;
                }
            }
            if (sign) break;
        }
        if (!sign){
            printPath(k+1,false);
        }
    }
    return 0;
}
