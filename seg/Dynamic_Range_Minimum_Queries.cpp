#include<bits/stdc++.h>
using namespace std;
 void build(int i,int start,int end,long long seg[],long long  a[]){
    if(end==start){
        seg[i]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    build(2*i+1,start,mid,seg,a);
    build(2*i+2,mid+1,end,seg,a);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
    
 }
 long long query(int i,int l ,int r,int start,int end,long long seg[]){
    if(end<l||r<start){
        return INT_MAX;
    }
    if(start>=l&&end<=r){
        return seg[i];
    }
    long long  mid=(start+end)>>1;
    long long  left=query(2*i+1,l,r,start,mid,seg);
    long long  right=query(2*i+2,l,r,mid+1,end,seg);
    return min(left,right);

 }
  void update(int i,int start,int end,int val,int index,long long  seg[]){
    if(start==end){
        seg[i]=val;
        return;
    }
    int mid=(start+end)>>1;
    if(index<=mid)
    update(2*i+1,start,mid,val,index,seg);
    else
    update(2*i+2,mid+1,end,val,index,seg);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);

  }

int main(){
    int n,m;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++){
    cin>>a[i];
    }
    long long seg[4*n+1];
    build(0,0,n-1,seg,a);
    while(m--){
        int t;
        cin>>t;
        if(t==1){
         int k,i;
         cin>>k>>i;
         update(0,0,n-1,i,k-1,seg);
         
        }else{
            int l,r;
            cin>>l>>r;
            
           cout<<query(0,l-1,r-1,0,n-1,seg)<<endl;
        }
    }
    
    
}