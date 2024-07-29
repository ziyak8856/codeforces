#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    map<int,int>mp;
    for(auto it:arr)mp[it]++;
    vector<int>nums;
    for(auto it:mp)nums.push_back(it.first);
    vector<long long>dp(nums.size());
    for(int i=0;i<nums.size();i++){
        long long c=nums[i]*(long long)mp[nums[i]];
        dp[i]=c;
        if(i==0){
           
        }else if(i==1){
            if(nums[i]-nums[i-1]>1)
            dp[i]=dp[i]+dp[i-1];
            else
           dp[i]=max(dp[i],dp[i-1]);

        }else{
            if(nums[i]-nums[i-1]>1){
                dp[i]+=dp[i-1];
            }else{
                dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
            }
        }
    }
    //for(auto it:dp)cout<<it<<" ";
   cout<<dp[nums.size()-1];
}