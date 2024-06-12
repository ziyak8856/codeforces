#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//786
int main(){
   ll t=1;
  cin>>t;
   while(t--){
      ll n;
      cin>>n;
      ll a[n];
      ll s=0;
      for(ll i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
      }
      ll x=s/n;
      ll c=0;
      ll f=1;
      for(ll i=0;i<n;i++){
        c+=(a[i]-x);
        if(c<0){
            cout<<"NO\n";
            f=0;
            break;
        }
      }
      if(c==0)cout<<"YES\n";
      

   }
}