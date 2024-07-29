#include<bits/stdc++.h>
using namespace std;
 int numOfSubarrays(vector<int>& arr) {
        map<int,int>mp;
        int n=arr.size();
        int c=0;
        int sum=0;
        int m=1e9+7;
        mp[0]=1;
        for(int i=0;i<n;i++){
           // if(arr[i]%2==1)c++;
            sum=(sum%m+arr[i]%m);
            int t=sum%2;
            t=1-t;
            c=(c%m+mp[t]%m)%m;
            mp[1-t]++;
        }
        return c%m;
    }
int find_div(int n){
    int c=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i==n)c++;
            else c+=2;
        }
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }

    vector<int>div(n);
    for(int i=0;i<n;i++){
        div[i]=find_div(a[i]);
    }
   // for(auto it:div)cout<<it<<" ";
    cout<<numOfSubarrays(div);

}