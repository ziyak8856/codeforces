#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<bool>&vis,vector<int>adj[]){
    vis[u]=true;
    for(auto it :adj[u]){
        if(!vis[it])dfs(it,vis,adj);
    }

}
int main(){
     int n,m;
     cin>>n>>m;
     int a,b;
     vector<int>adj[n+1];
     vector<bool>vis(n+1,false);
     for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
     }
     int c=0;
     vector<int>ans;
     for(int i=1;i<=n;i++){
        if(!vis[i]){
            c++;
            ans.push_back(i);
            dfs(i,vis,adj);
        }
     }
     cout<<c-1<<endl;
     for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
     }



}