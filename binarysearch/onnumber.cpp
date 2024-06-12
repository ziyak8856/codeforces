#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bs(ll i,ll k,ll j,ll n){
    ll ans=0;
    while(i<=j){
        ll mid=i+(j-i)/2;
        ll indx=mid/n;
        indx=mid-indx;
        if(indx==k){
           ans=mid;
           j=mid-1;
        }else if(indx<k){
            i=mid+1;
        }else {
            j=mid-1;
        }

    }
    cout<<ans<<endl;
    return ;

 }
int main(){
   ll t;
   cin>>t;
   while(t--){
    ll n,k;
    cin>>n>>k;
    bs(1,k,1e15,n);
   }
}