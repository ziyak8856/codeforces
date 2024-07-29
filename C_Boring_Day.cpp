#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int c=0;
        int s=0;
        for(ll i=0;i<n;i++){
          if(s>=l&&s<=r){
            s+=a[i];
            c++;
          }else if(s<l){
            s+=a[i];
            // if(s>=l&&s<=r)c++;
            //if(s>r)c++;
            //cout<<a[i]<<" ";
          }else{
            
            //cout<<a[i]<<" ";
            s=a[i];
          }
        }
        cout<<c<<endl;
    }
  
}