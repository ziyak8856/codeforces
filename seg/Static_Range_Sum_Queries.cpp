#include<bits/stdc++.h>
using namespace std;
 void build(int i,int start,int end,vector<long long>&seg,long long  a[]){
    if(end==start){
        seg[i]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    build(2*i+1,start,mid,seg,a);
    build(2*i+2,mid+1,end,seg,a);
    seg[i]=seg[2*i+1]+seg[2*i+2];

 }
 long long query(int i,int start,int end,int l,int r,vector<long long>&seg){
     if(end<l||r<start){
        return 0;
    }
    if(start>=l&&end<=r){
        return seg[i];
    }
    long long mid=(start+end)>>1;
    long long left=query(2*i+1,start,mid,l,r,seg);
    long long right=query(2*i+2,mid+1,end,l,r,seg);
    return left+right;
 }
 
int main(){
    long long n,q;
    cin>>n>>q;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long>seg(4*n+1);

    build(0,0,n-1,seg,a);

   // cout<<seg[0];
    while(q--){
       int l,r;
       cin>>l>>r;
       cout<<query(0,0,n-1,l-1,r-1,seg)<<endl;


    }
   
    //cout<<seg[0].first;
    
}