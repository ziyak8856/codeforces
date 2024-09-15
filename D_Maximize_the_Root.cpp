#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,vector<int>adj[],vector<bool>&vis,int req,vector<int>&a){
    vis[i]=true;
    bool f=true;
    bool leaf=true;
    for(auto it:adj[i]){
        if(!vis[it]){
          if(req<=a[it])f=f&dfs(it,adj,vis,req,a);
          else f=f&dfs(it,adj,vis,(2*req-a[it]),a);
          leaf=false;
        }
    }
   
     vis[i]=false;
     if(leaf&&a[i]>=req)return true;
    if(leaf)return false; 
    return f;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1);
        int s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s+=a[i];
        }
        vector<int>adj[n+1];
        for(int i=0;i<n-1;i++){
            int x;
            cin>>x;
            adj[x].push_back(i+2);
            adj[i+2].push_back(x);
        }
        int l=0;
        int r=s;
        int ans=0;
        vector<bool>vis(n+1,false);
        while(l<=r){
            int mid=(l+r)/2;
            //cout<<mid<<" ";
            int rq;
            if(a[1]<mid)rq=mid-a[1];
            else rq=0;
            if(dfs(1,adj,vis,rq,a)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
            // for(auto it:vis)cout<<it<<" ";
            // cout<<endl;

        }
        //cout<<endl;
        cout<<ans<<endl;

    }
}