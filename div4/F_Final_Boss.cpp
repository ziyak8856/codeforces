#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll check_fun(vector<ll>gun,vector<ll>cool_down,ll n,ll power){
      ll c=0;
      for(ll i=0;i<n;i++){
        c+=(ceil(power/(double)cool_down[i]))*gun[i];
      }
      return c;
}
ll b_search(vector<ll>gun,vector<ll>cool_down,ll n,ll power){
    ll l=0;
    ll r=*max_element(cool_down.begin(),cool_down.end())*(1e6);
   // ll r=1e12;
    ll ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        ll check=check_fun(gun,cool_down,n,mid);
        if(check>=power){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;

}
int main(){
    ll t;
   cin>>t;
   while(t--){
    ll power,n;
    cin>>power>>n;
    vector<ll>gun(n);
    vector<ll>cool_down(n);
    for(ll i=0;i<n;i++){
        cin>>gun[i];
    }
     for(ll i=0;i<n;i++){
        cin>>cool_down[i];
    }
    cout<<b_search(gun,cool_down,n,power)<<endl;
    
   }
}