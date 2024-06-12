#include<bits/stdc++.h>
using namespace std;
  void dfs(int i,int j,vector<vector<char>>&mat,vector<int>&dr,vector<int>&dc,int n,int m){
    mat[i][j]='#';
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr>=0&&nc>=0&&nr<n&&nc<m&&mat[nr][nc]=='.'){
            dfs(nr,nc,mat,dr,dc,n,m);
        }
    }
    
  }
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>mat(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int c=0;
    vector<int>dr={0,0,-1,1};
    vector<int>dc={-1,1,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='.'){
                c++;
                dfs(i,j,mat,dr,dc,n,m);
            }
        }
    }
    cout<<c;
}