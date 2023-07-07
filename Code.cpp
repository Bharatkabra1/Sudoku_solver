#include<bits/stdc++.h>
using namespace std;
const int Boardsize = 9;
const int Cellsize = 3;
int board[Boardsize][Boardsize];
bool check(int ch, int row, int col){
    //for check in row
    for(int c=0;c<Boardsize;c++){
        if(c!=col && board[row][c]==ch){
            return false;
        }
    }
    //for check in column
    for(int r=0;r<Boardsize;r++){
        if(r!=row && board[r][col]==ch){
            return false;
        }
    }
    //for check in square
    int str=(row/Cellsize)*Cellsize;
    int stc=(col/Cellsize)*Cellsize;
    for(int dx=0;dx<Cellsize;dx++){
        for(int dy=0;dy<Cellsize;dy++){
            if(str+dx==row && stc+dy==col){
                continue;
            }
            if(board[str+dx][stc+dy]==ch){
                return false;
            }
        }
    }return true;
}
int ans=0;
void rec(int row, int col){
    if(col==Boardsize){
        rec(row+1,0);
        return;
    }
    if(row==Boardsize){
        //base case
        ans++;
        for(int i=0;i<Boardsize;i++){
            for(int j=0;j<Boardsize;j++){
                cout<<board[i][j]<<" ";
            }
        }return;
    }
    if(board[row][col]==0){
        //we need to fill
        for(int ch=1;ch<=Boardsize;ch++){
            if(check(ch,row,col)){
                board[row][col]=ch;
                rec(row,col+1);
                board[row][col]=0;
            }
        }
    }else{
        //pre-filled
        if(check(board[row][col],row,col)){
            rec(row,col+1);
        }
    }
}
void solve(){
    for(int i=0;i<Boardsize;i++){
        for(int j=0;j<Boardsize;j++){
            cin>>board[i][j];
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int _t=1; //cin>>_t;
    while(_t--){
        solve();
     }
}
