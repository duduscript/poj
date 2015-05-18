#include <iostream>
#include <cstring>
using namespace std;
bool map[30][30];
int direction[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int c[30],r[30];
int N,col,row,time,pointNum;
bool dfs(int _col,int _row){
    c[pointNum] = _col;
    r[pointNum] = _row;
    map[_col][_row] = 1;
    if (++pointNum == N) return true;
    int newCol,newRow;
    bool sign = false;
    for(int i=0;i!=8;++i){
        newCol = _col+direction[i][0];
        newRow = _row+direction[i][1];
        if( newCol>=0 && newCol<col && newRow>=0 && newRow<row
                && !map[newCol][newRow]
                && dfs(newCol,newRow)){
            sign = true;
            break;
        }
    }
    if (sign) return true;
    pointNum--;
    map[_col][_row] = 0;
    return false;
}
void printPath(int k,bool sign){
    cout<<"Scenario #"<<k<<":"<<endl;
    if(sign){
        char ch;
        for(int i=0; i!= pointNum;++i){
            ch = 'A' + c[i];
            cout<<ch<<r[i]+1;
        }
        cout<<endl;
    }else{
        cout<<"impossible"<<endl;
    }
    cout<<endl;
}
int main()
{
    cin>>time;
    int inputCol[30],inputRow[30];
    for(int k=0;k!=time;++k)
        cin>>inputRow[k]>>inputCol[k];
    for(int k=0; k!=time; ++k){
        memset(map,0,sizeof(map));
        memset(c,0,sizeof(c));
        memset(r,0,sizeof(r));
        col = inputCol[k];
        row = inputRow[k];
        N = col*row;
        bool sign = false;
        pointNum = 0;
        for(int i=0;i<=col/2;++i){
            for(int j=0;j<=row/2;++j){
                if(dfs(i,j)){
                    printPath(k+1,true);
                    sign = true;
                    break;
                }
            }
            if (sign) break;
        }
        if (!sign)  printPath(k+1,false);
    }
    return 0;
}
