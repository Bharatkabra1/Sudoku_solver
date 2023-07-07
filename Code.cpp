#include<bits/stdc++.h>
using namespace std;

#define int long long
int ans=0,n,cellsize;
int a[100][100]; 

bool check(int ch,int row,int col)
{
    for(int c=0;c<n;c++)
    {
        if(c!=col && a[row][c]==ch)
            return false;
    }

    for(int r=0;r<n;r++)
    {
        if(r!=row && a[r][col]==ch)
            return false;
    }

    int str=(row/cellsize)*cellsize;
    int stc=(col/cellsize)*cellsize;

    for(int dx=0;dx<cellsize;dx++)
    {
        for(int dy=0;dy<cellsize;dy++)
        {
            if((str+dx)==row && (stc+dy)==col)
                continue;

            if(a[str+dx][stc+dy]==ch)
                return false;
        }
    }

    return true;
}

void rec(int row, int col)
{
    if(col==n)
    {
        rec(row+1,0);
        return;
    }
    if(row==n)
    {
        ans++;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }

        return;
    }

    if(a[row][col]==0)
    {
        for(int ch=1;ch<=n;ch++)
        {
            if(check(ch,row,col))
            {
                a[row][col]=ch;
                rec(row,col+1);
                a[row][col]=0;
            }
        }
    }
    else
    {
        if(check(a[row][col],row,col))
        {
            rec(row,col+1);
        }
    }
}

void solve()
{
    cin>>n>>cellsize;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    rec(0,0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
}
