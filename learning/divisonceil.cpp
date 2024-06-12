#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll t=1;
   // cin>>t;
    while(t--){
        ll  n,m,a;
        cin>>n>>m>>a;
        
        ll ans =(ll)ceil(n/(double)a)*(ll)ceil(m/(double)a);
        cout<<ans;
       
        
    }
}