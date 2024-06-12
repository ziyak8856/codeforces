#include<bits/stdc++.h>
using namespace std;
  int dp[505][505][26];
  int solve(int i,int j,int k,vector<int>&nums,int &n){
 
    if(i>=n){
        return 0;
    }
    if(dp[i][j+1][k]!=-1)return dp[i][j+1][k];
    int take=0,nt=0;
    if(j==-1||nums[i]==nums[j]){
        take=1+solve(i+1,i,k,nums,n);
    } else if(k>0){
            take=1+solve(i+1,i,k-1,nums,n);
         
    }
    nt=solve(i+1,j,k,nums,n);
    return dp[i][j+1][k] =max(take,nt);

}

int maximumLength(vector<int>& nums, int k) {
    int n=nums.size();
   // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+2,vector<int>(26,-1)));
      memset(dp,-1,sizeof(dp));
      return solve(0,-1,k,nums,n);
    }
int main(){
   vector<int>nums = {1,2,1,1,3};
   int k = 3;
   cout<<maximumLength(nums,k);
}