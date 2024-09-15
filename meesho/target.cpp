#include<bits/stdc++.h>
using namespace std;
 int mod=1e9+7;
    int dp[1001][1001];
    long long  solve(int i,int j,vector<vector<int>>&f,string &tar,int &n){
        if(i>=tar.size())return 1;
        if(j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long t=(f[j][tar[i]-'a']*solve(i+1,j+1,f,tar,n))%mod;
        long long  nt=solve(i,j+1,f,tar,n)%mod;
        return dp[i][j]=(t%mod+nt%mod)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int m=words[0].size();
        vector<vector<int>>f(m,vector<int>(26,0));
        for(int i=0;i<m;i++){
            for(auto w:words){
                f[i][w[i]-'a']++;
            }
        }
        memset(dp,-1,sizeof(dp));
       // vector<vector<long long>>dp(target.size()+1,vector<long long >(m+1,-1));
        return solve(0,0,f,target,m);

    }
int main(){
    vector<string>words={"valya","lyglb","vldoh"};
    string target="val";
    
     cout<<numWays(words,target);
     
}