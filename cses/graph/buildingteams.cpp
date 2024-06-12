#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int>adj[n+1];
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    vector<int>vis(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]!=-1)continue;;
    vis[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto it:adj[u]){
            if(vis[it]==-1){
                if(vis[u]==2)vis[it]=1;
                else vis[it]=2;
                q.push(it);

            }else if(vis[it]==vis[u]){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    }
    for(int i=1;i<=n;i++)cout<<vis[i]<<" ";


}