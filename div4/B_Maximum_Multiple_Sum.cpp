#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    int mx=INT_MIN;
    int no=-1;
    for(int i=2;i<=n;i++){
        int ans=0;
      for(int j=1;j*i<=n;j++){
        ans+=j*i;
    
      }
      if(mx<ans){
        mx=ans;
        no=i;
      }
   }
   cout<<no<<endl;

   }
   
}