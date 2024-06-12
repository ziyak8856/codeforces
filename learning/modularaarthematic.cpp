#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/1931/problem/Ds
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
       
        ll  n,x,y;
        cin>>n>>x>>y;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=0;
        map<pair<ll,ll>,ll>mp;
        for(ll i=0;i<n;i++){
            ll ay=a[i]%y;
            ll ax=a[i]%x;
           
            if(mp.find(make_pair((x-ax)%x,ay))!=mp.end())ans+=mp[make_pair((x-ax)%x,ay)];
             mp[make_pair(ax,ay)]++;
        }
        cout<<ans<<endl;
       
    }
}