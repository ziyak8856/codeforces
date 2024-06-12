#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
   ll t;
   cin>>t;
   while(t--){
     ll mx=0;
     ll n;
     cin>>n;
     ll ans=0;
     ll a[n];
     for(ll i=0;i<n;i++){
        cin>>a[i];
     }
     ll sum=0;
     for(ll i=0;i<n;i++){
        mx=max(a[i],mx);
        sum+=a[i];
        if(sum-mx==mx)ans++;
     }
     cout<<ans<<endl;
     
   }
}