#include<bits/stdc++.h>
using namespace std;

int bsu(int l,int r,vector<int>&a,int k){
  int ans=-1;
  while(l<=r){
    int mid=(l+r)/2;
    if(a[mid]<=k){
      ans=mid;
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  return ans;
}
int bsl(int l,int r,vector<int>&a,int k){
  int ans=-1;
  while(l<=r){
    int mid=(l+r)/2;
    if(a[mid]>=k){
      ans=mid;
      r=mid-1;
    }else{
      //ans=;
      l=mid+1;
    }
  }
  return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    int l,r;
    cin>>l>>r;
    int ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
      int low=bsl(i+1,n-1,a,abs(a[i]-l));
      int high=bsu(i+1,n-1,a,abs(a[i]-r));
      if(low==-1||high==-1){
       continue;
      }else{
        ans+=(high-low+1);
      }
     // cout<<endl;
    }
    cout<<ans;

}