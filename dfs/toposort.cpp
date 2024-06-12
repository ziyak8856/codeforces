#include<bits/stdc++.h>
//https://codeforces.com/contest/1931/problem/F
using namespace std;
typedef long long ll;
bool dfs(int u,vector<bool>&path,vector<bool>&vis,set<ll>adj[],ll n){
    vis[u]=true;
    path[u]=true;
    for(auto it:adj[u]){
        if(!vis[it]){
            if(dfs(it,path,vis,adj,n))return true;
        }else if(path[it]){
         return true;
        }
    }
    path[u]=false;
    return false;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
      ll n;
      ll k;
      cin>>n>>k;
      set<ll>adj[n+1];
      ll a[k][n];
      for(ll i=0;i<k;i++){
        for(ll j=0;j<n;j++){
          cin>>a[i][j];

        }
      }
     // set<pair<int,int>>st;
     // bool mat[n+1][n+1]={false};
      for(ll i=0;i<k;i++){
        for(ll j=1;j<n-1;j++){
            adj[a[i][j]].insert(a[i][j+1]);

        }
      }
      

      vector<bool>vis(n+1,false);
      vector<bool>pathvis(n+1,false);
      ll f=1;
      for(ll i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,pathvis,vis,adj,n)){
                cout<<"NO\n";
                //break;
                f=0;

            }
        }
        if(f==0)break;
      }
      
      if(f==1)cout<<"YES\n";
        
       
    }
}