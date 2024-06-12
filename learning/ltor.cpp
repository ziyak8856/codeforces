#include<bits/stdc++.h>
//https://codeforces.com/contest/1927/problem/D
//ltor binary search 
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int rarr[n];
        rarr[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(a[i]==a[i+1])rarr[i]=rarr[i+1];
            else rarr[i]=i+1;
            
        }
       int q;
       cin>>q;
       while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(rarr[l]==-1||rarr[l]>r){
            cout<<-1<<" "<<-1<<endl;
        }else{
            cout<<l+1<<" "<<rarr[l]+1<<endl;
        }
       }
       cout<<" "<<endl;
    }
   
}