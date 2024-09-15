#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];
        // for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
        // cout<<endl;
        while(q--){
            int l,r,x;
            cin>>l>>r>>x;
            int sum=pre[l-1]+pre[n]-pre[r];
            sum+=(r-l+1)*x;
            if(sum%2)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}