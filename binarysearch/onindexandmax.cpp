#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 int bs(ll k,ll a[],ll n){
    ll i=0;
    ll j=n-1;
    while(i<=j){
        ll mid=i+(j-i)/2;
        if(a[mid]<=k){
            i=mid+1;
        }else{
            j=mid-1;
        }

    }
    return i;

 }
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll  n;
        cin>>n;
        ll q;
        cin>>q;
        ll a[n];
        for(ll i=0;i<n;i++){
        cin>>a[i];
        }
       // sort(a,a+n);
        ll pre[n];
        ll ma=INT64_MIN;
        ll ind=0;
        ll s=0;
        for(ll i=0;i<n;i++){
            s+=a[i];
            ma=max(ma,a[i]);
            a[i]=ma;
            pre[i]=s;
        }

        ll x;
        //for(auto it:a)cout<<it<<" ";
        while(q--){
            cin>>x;
            int indx=bs(x,a,n);
            if(x<a[0])cout<<0<<" ";
            else
            cout<<pre[indx-1]<<" ";
        }
        cout<<"\n";
        

        
    }
}