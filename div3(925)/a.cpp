#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//786
ll cntz(ll n){
    ll c=0;
    while(n){
        if(n%10==0)c++;
        else return c;
        n=n/10;
    }
    return c;
}
ll cntd(ll n){
    ll c=0;
    while(n){
        c++;
        n/=10;
    }
    return c;
}
int main(){
   ll t=1;
  cin>>t;
   while(t--){
      ll n;
      cin>>n;
      ll m;
      cin>>m;
      vector<ll>zero(n,0);
      ll x;
      ll total=0;
      for(ll i=0;i<n;i++){
        cin>>x;
        total+=cntd(x);
        zero[i]=cntz(x);
      }
       sort(zero.begin(),zero.end());
       x=0;
       for(ll i=n-1;i>=0;i-=2){
         x+=zero[i];
       }
       if(total-x>m)cout<<"Sasha\n";
       else cout<<"Anna\n";
    // for(auto it:zero)cout<<it<<" ";
    // cout<<endl;
    // cout<<total<<" "<<x<<endl;


   }
}