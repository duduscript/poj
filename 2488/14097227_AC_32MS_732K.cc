#include <iostream>
#include <cstring>
using namespace std;
bool map[100][100];
int direction[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int c[100],r[100];
int N,col,row,time,pointNum;
bool dfs(int _col,int _row){
    c[pointNum] = _col;
    r[pointNum] = _row;
    map[_col][_row] = 1;
    if (++pointNum == N) return true;
    for(int i=0;i!=8;++i){
        int newCol = _col+direction[i][0];
        int newRow = _row+direction[i][1];
        if( newCol>=0 && newCol<col && newRow>=0 && newRow<row
                && !map[newCol][newRow]
                && dfs(newCol,newRow)){
            return true;
        }
    }
    pointNum--;
    map[_col][_row] = 0;
    return false;
}
void printPath(int k,bool sign){
    cout<<"Scenario #"<<k<<":"<<endl;
    if(sign){
        for(int i=0; i!= pointNum;++i){
            char ch = 'A' + c[i];
            cout<<ch<<r[i]+1;
        }
    }else{
        cout<<"impossible";
    }
    cout<<"\n\n";
}
int main(){
    cin>>time;
    int inputCol[100],inputRow[100];
    for(int k=0;k!=time;++k)
        cin>>inputRow[k]>>inputCol[k];
    for(int k=0; k!=time; ++k){
        memset(map,0,sizeof(map));
        col = inputCol[k];
        row = inputRow[k];
        N = col*row;
        bool sign = false;
        pointNum = 0;
        for(int i=0;i<=col/2;++i){
            for(int j=0;j<=row/2;++j){
                if(dfs(i,j)){
                    sign = true;
                    break;
                }
            }
            if (sign) break;
        }
        printPath(k+1,sign);
    }
    return 0;
}
