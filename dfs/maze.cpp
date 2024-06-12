//https://codeforces.com/problemset/problem/377/A
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dr[4]={-1,1,0,0};
ll dc[4]={0,0,-1,1};
void dfs1(ll i,ll j,vector<vector<char>>&a,ll n,ll m,ll &c,ll &k){
    a[i][j]='X';
    c++;
    if(c==k)return;
    for(ll k=0;k<4;k++){
     ll nr=i+dr[k];
     ll nc=j+dc[k];
     if(nc>=0&&nr>=0&&nc<m&&nr<n){
         if((nc-1<0||a[nr][nc-1]!='.')&&(nc+1>=m||a[nr][nc+1]!='.')&&(nr+1>=n||a[nr+1][nc]!='.')&&a[nr][nc]=='.'){
              dfs1(nr,nc,a,n,m,c,k);
             }else if((nc-1<0||a[nr][nc-1]!='.')&&(nc+1>=m||a[nr][nc+1]!='.')&&(nr-1<0||a[nr-1][nc]!='.')&&a[nr][nc]=='.'){
              dfs1(nr,nc,a,n,m,c,k);
             }else if((nc-1<0||a[nr][nc-1]!='.')&&(nr-1<0||a[nr-1][nc]!='.')&&(nr+1>=n||a[nr+1][nc]!='.')&&a[nr][nc]=='.'){
             dfs1(nr,nc,a,n,m,c,k);
             }else if((nc+1>=m||a[nr][nc+1]!='.')&&(nr-1<0||a[nr-1][nc]!='.')&&(nr+1>=n||a[nr+1][nc]!='.')&&a[nr][nc]=='.'){
             dfs1(nr,nc,a,n,m,c,k);
             }
     }
 
    }
 
}

void dfs2(ll nc,ll nr,vector<vector<char>>&a,ll n,ll m,ll &c,ll &k){
    
    a[nr][nc]='X';
    c++;
    if(c>=k)return;
    for(ll k=0;k<4;k++){
     ll i=nr+dr[k];
     ll j=nc+dc[k];
     if(j>=0&&i>=0&&j<m&&i<n){
         if((j-1<0||a[i][j-1]!='.')&&(j+1>=m||a[i][j+1]!='.')&&a[i][j]=='.'){
             dfs2(i,j,a,n,m,c,k);
             }else if((j-1<0||a[i][j-1]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
               dfs2(i,j,a,n,m,c,k);
             }else if((j-1<0||a[i][j-1]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
               dfs2(i,j,a,n,m,c,k);
             }else if((j+1>=m||a[i][j+1]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
               dfs2(i,j,a,n,m,c,k);
             }else if((j+1>=m||a[i][j+1]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
               dfs2(i,j,a,n,m,c,k);              
             }else if((i+1>=n||a[i+1][j]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
               dfs2(i,j,a,n,m,c,k);
             }
     }

    }

}
int main(){
   ll t=1;
   //cin>>t;
  
   while(t--){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>>a(n,vector<char>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
      queue<pair<ll,ll>>q;
     ll c=0;
     for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
             if(c>=k)break;
             if((j-1<0||a[i][j-1]!='.')&&(j+1>=m||a[i][j+1]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
              dfs1(i,j,a,n,m,c,k);
             }else if((j-1<0||a[i][j-1]!='.')&&(j+1>=m||a[i][j+1]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
              dfs1(i,j,a,n,m,c,k);
             }else if((j-1<0||a[i][j-1]!='.')&&(i-1<0||a[i-1][j]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
              dfs1(i,j,a,n,m,c,k);
             }else if((j+1>=m||a[i][j+1]!='.')&&(i-1<0||a[i-1][j]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
              dfs1(i,j,a,n,m,c,k);
             }
        }
    } //&&(i+1>=n||a[i+1][j]!='.')
    if(c<k){
        for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
             if(c>=k)break;
             if((j-1<0||a[i][j-1]!='.')&&(j+1>=m||a[i][j+1]!='.')&&a[i][j]=='.'){
                dfs2(i,j,a,n,m,c,k);
             }else if((j-1<0||a[i][j-1]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
                dfs2(i,j,a,n,m,c,k);
             }else if((j-1<0||a[i][j-1]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
                dfs2(i,j,a,n,m,c,k);
             }else if((j+1>=m||a[i][j+1]!='.')&&(i+1>=n||a[i+1][j]!='.')&&a[i][j]=='.'){
                dfs2(i,j,a,n,m,c,k);
             }else if((j+1>=m||a[i][j+1]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
                dfs2(i,j,a,n,m,c,k);
             }else if((i+1>=n||a[i+1][j]!='.')&&(i-1<0||a[i-1][j]!='.')&&a[i][j]=='.'){
                dfs2(i,j,a,n,m,c,k);
             }
        }
    }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }

   


   }
}