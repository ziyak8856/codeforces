#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>adj[],vector<int>&start,vector<int>&end,vector<bool>&vis,int &cnt){
    vis[i]=true;
    start[i]=cnt++;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,adj,start,end,vis,cnt);
        }
    }
    end[i]=cnt++;
    return ;

}
int main(){
    int n=5;
    vector<vector<int>>edg={{1,2},{2,3},{1,4},{1,5}};
    vector<vector<int>>q={{1,3},{2,5}};
    vector<int>adj[n+1];
    vector<bool>vis(n+1,false);
    for(auto it:edg){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int c=1;
    vector<int>start(n+1);
    vector<int>end(n+1);
    dfs(1,adj,start,end,vis,c);
    // for(int i=1;i<=n;i++){
    //     cout<<start[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<end[i]<<" ";
    // }
    for(auto it:q){
        int p=it[0];
        int c=it[1];
        if(start[p]<=start[c]&&end[p]>=end[c])cout<<1<<" ";
        else cout<<0<<" ";

    }

}