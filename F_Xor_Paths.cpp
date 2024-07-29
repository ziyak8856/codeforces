#include<bits/stdc++.h>
using namespace std;
map<long long ,long long>dp[30][30]; 
long long  dfs(long long i,long long  j,vector<vector<long long >>&a,long long  x,long long &k,long long  &n,long long  &m){
    x=x^a[i][j];
    if(i==n-1&&j==m-1)return x==k;
    long long  l=0,r=0;
    if(dp[i][j].find(x)!=dp[i][j].end())return dp[i][j][x];
    if(i+1<n)
    l=dfs(i+1,j,a,x,k,n,m);
    if(j+1<m)
    r=dfs(i,j+1,a,x,k,n,m);
    return dp[i][j][x]= l+r;
    
}
int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<vector<long long >>a(n,vector<long long >(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
   // vector<vector<map<long long ,long long >>>dp(n+1,vector<map<long long ,long long >>(m+1,map<long long ,long long >()));
    cout<<dfs(0,0,a,0,k,n,m);

}