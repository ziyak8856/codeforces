#include<bits/stdc++.h>
using namespace std;
// the number of ways to match chokudai and chchokudai is 3  
// ch okudai 
// c hokudai
//   chokudai
int mod=1e9+7;
 int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(j>=t.size())return 1;
    if(i>=s.size())return 0;
    if(t.size()-j>s.size()-i)return 0;
    if(dp[i][j]!=-1)return dp[i][j]%mod;
    if(s[i]!=t[j])return dp[i][j]=solve(i+1,j,s,t,dp)%mod;
    return dp[i][j]=(solve(i+1,j+1,s,t,dp)%mod+solve(i+1,j,s,t,dp)%mod)%mod;

 }
int main(){
   string s;
   string t;
   cin>>s;
   t="chokudai";
   vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
   cout<<solve(0,0,s,t,dp)%mod;

}