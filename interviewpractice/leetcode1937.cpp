#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        int ans=0;
        vector<vector<int>>dp=points;
        for(int i=n-2;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int val=points[i][j];
                for(int k=m-1;k>=0;k--){
                    dp[i][j]=max(dp[i][j],val+dp[i+1][k]-abs(k-j));
                    ans=max(dp[i][j],ans);
                }
            }
        }
        // for(auto it:dp){
        //     for(auto x:it)cout<<x<<" ";
        //     cout<<endl;
        // }
        return *max_element(dp[0].begin(),dp[0].end());
    }

};
int main(){
    vector<vector<int>>p={{1,5},{2,3},{4,2}};
    Solution solve;
    cout<<solve.maxPoints(p);
}