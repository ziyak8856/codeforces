#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll  n;
        cin>>n;
        map<ll,ll>mp;
        ll a;
        ll mx=INT_MIN;
        for(ll i=0;i<n;i++){
            cin>>a;
            mx=max(mx,a);
            mp[a]=i;
        }
        ll ans=-1;
        for(ll i=1;i<=mx;i++){
            for(ll j=i;j<=mx;j++){
                if(mp.find(i)!=mp.end()&&mp.find(j)!=mp.end()&&__gcd(i,j)==1){
                    ans=max(ans,mp[i]+mp[j]+2);
                }
            }
        }
        cout<<ans<<endl;
        
        
    }
}