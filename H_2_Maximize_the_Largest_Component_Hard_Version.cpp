#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<int>>&a,vector<string>&ans,int n,string s){
    if(i==n-1&&j==n-1){
        ans.push_back(s);
        return ;

    }
    //cout<<s<<" ";
    a[i][j]=0;
    if(i+1<n&&a[i+1][j]==1)
    dfs(i+1,j,a,ans,n,s+'D');
    if(i-1>=0&&a[i-1][j]==1)
    dfs(i-1,j,a,ans,n,s+'U');
     if(j+1<n&&a[i][j+1]==1)
    dfs(i,j+1,a,ans,n,s+'R');
    if(j-1>=0&&a[i][j-1]==1)
    dfs(i,j-1,a,ans,n,s+'L');
    a[i][j]=1;

    
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    vector<string>ans;
   dfs(0,0,a,ans,n,"");
        if(a[0][0]==0)cout<<" ";
        else
        for(auto x:ans)cout<<x<<" ";
    //     cout<<endl;
    

}