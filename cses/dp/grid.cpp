#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
long long solve(int i,int j,vector<vector<char>>&a,int n,vector<vector<long long >>&dp){
    if(i==n-1&&j==n-1&&a[i][j]=='.')return 1;
    long long  left=0,down=0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(i+1<n&&j<n&&a[i+1][j]!='*')
    left=solve(i+1,j,a,n,dp);
    if(j+1<n&&i<n&&a[i][j+1]!='*')
    down=solve(i,j+1,a,n,dp);
    return dp[i][j]=(left%mod+down%mod)%mod;

}
int main(){
   int n;
   cin>>n;
   vector<vector<char>>a(n,vector<char>(n));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
   }
   vector<vector<long long>>dp(n,vector<long long >(n,-1));
  if(a[0][0]=='*'){
    cout<<0;
    return 0;
  }
   cout<<solve(0,0,a,n,dp);



}