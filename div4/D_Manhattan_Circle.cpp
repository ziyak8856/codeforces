#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
     int n,m;
     cin>>n>>m;
     char a[n][m];
     int fi=-1;
     int fj=-1;
     int li=-1;
     int lj=-1;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                if(fi==-1){
                  fi=i;
                  fj=j;
                }
                li=i;
                lj=j;
            }
        }
     }
     fi++;
     li++;
     fj++;
     lj++;
     //cout<<fi<<" "<<fj<<" ";
     
     if(fi==li)cout<<fi<<" "<<fj;
     else cout<<(fi+li)/2<<" "<<fj;
     cout<<endl;


   }
}