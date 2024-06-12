#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c=0;
    queue<int>q;
    vector<bool>vis(n+1,false);
    vector<int>parent(n+1,-1);
    vis[1]=true;
    q.push(1);
    int l=1;
    while(!q.empty()){
      int size=q.size();
      while(size--){
        int u=q.front();
        if(u==n){
            cout<<l<<"\n";
            vector<int>ans;
            //ans.push_back(n);
            while(u!=-1){
                ans.push_back(u);
                u=parent[u];
            }
            int s=ans.size();
            for(int i=s-1;i>=0;i--)cout<<ans[i]<<" ";
            //for(auto it:parent)cout<<it<<" ";
            return 0;

        }
        q.pop();
        for(auto it:adj[u]){
            if(!vis[it]){
             parent[it]=u;
             vis[it]=true;
             q.push(it);
            }
        }

      }
      l++;
    }
   // for(auto it:parent)cout<<it<<" ";
    cout<<"IMPOSSIBLE";
    
}