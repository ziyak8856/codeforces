#include<bits/stdc++.h>
using namespace std;
int solve(int i,vector<int>&a){
    if(i>=a.size())return 0;
    //adj
   return a[i]+max( solve(i+1,a),solve(i+2,a));

}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    //vector<int>dp(n+1,-1);
    for(int i=0;i<n;i++)cin>>a[i];

    cout<< max(solve(0,a),solve(1,a));
    
    //cout<<dp[0];
    
}