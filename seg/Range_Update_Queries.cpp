#include<bits/stdc++.h>
using namespace std;
//see i have two sol
// #include<bits/stdc++.h>
// using namespace std;
//  void build(int i,int start,int end,vector<pair<long long,long long >>&seg,long long  a[]){
//     if(end==start){
//         seg[i].first=a[start];
//         seg[i].second=0;
//         return;
//     }
//     int mid=(start+end)>>1;
//     build(2*i+1,start,mid,seg,a);
//     build(2*i+2,mid+1,end,seg,a);
//     seg[i].first=seg[2*i+1].first+seg[2*i+2].first;
//     seg[i].second=seg[2*i+1].second+seg[2*i+2].second;
    
//  }
//  long long query(int i,int index,int start,int end,vector<pair<long long,long long >>&seg){
//     if(start==end){
//         return seg[i].first+seg[i].second;
//     }
  
//     long long  mid=(start+end)>>1;
//     long long v=seg[i].second;
//     long long left=0,right=0;
//     if(mid>=index){
//         left=query(2*i+1,index,start,mid,seg);
//     }else {
//         right=query(2*i+2,index,mid+1,end,seg);
//     }
//     return left+right+v;
 
//  }
//   void update(int i,int start,int end,int val,int l,int r,vector<pair<long long,long long >>&seg){
//      if(start>=l&&end<=r){
//         seg[i].second+=val;
//         return;
//     }
//      if(end<l||r<start){
//         return ;
//     }
//     long long mid=(start+end)>>1;
//     update(2*i+1,start,mid,val,l,r,seg);
//     update(2*i+2,mid+1,end,val,l,r,seg);
//     return ;
//   }
 
// int main(){
//     long long n,q;
//     cin>>n>>q;
//     long long a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     vector<pair<long long,long long >>seg(4*n+1);
//     build(0,0,n-1,seg,a);
//     while(q--){
//         long long  t;
//         cin>>t;
//         if(t==2){
//             int ind;
//             cin>>ind;
//             ind--;
//            cout<<query(0,ind,0,n-1,seg)<<endl;
//         }else{
//             long long  l,r,x;
//             cin>>l>>r>>x;
//             update(0,0,n-1,x,l-1,r-1,seg);
 
 
//         }
//     }
   
//     //cout<<seg[0].first;
    
// }
 void build(int i,int start,int end,vector<pair<long long,long long >>&seg,long long  a[]){
    if(end==start){
        seg[i].first=a[start];
        seg[i].second=0;
        return;
    }
    int mid=(start+end)>>1;
    build(2*i+1,start,mid,seg,a);
    build(2*i+2,mid+1,end,seg,a);
    seg[i].first=seg[2*i+1].first+seg[2*i+2].first;
    seg[i].second=seg[2*i+1].second+seg[2*i+2].second;
    
 }
 long long query(int i,int index,int start,int end,vector<long long >&seg){
    if(start==end){
        return seg[i];
    }
  
    long long  mid=(start+end)>>1;
    long long v=seg[i];
    long long left=0,right=0;
    if(mid>=index){
        left=query(2*i+1,index,start,mid,seg);
    }else {
        right=query(2*i+2,index,mid+1,end,seg);
    }
    return left+right+v;

 }
  void update(int i,int start,int end,int val,int l,int r,vector<long long>&seg){
     if(start>=l&&end<=r){
        seg[i]+=val;
        return;
    }
     if(end<l||r<start){
        return ;
    }
    long long mid=(start+end)>>1;
    update(2*i+1,start,mid,val,l,r,seg);
    update(2*i+2,mid+1,end,val,l,r,seg);
    return ;
  }

int main(){
    long long n,q;
    cin>>n>>q;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long >seg(4*n+1,0);
   // build(0,0,n-1,seg,a);
    while(q--){
        long long  t;
        cin>>t;
        if(t==2){
            int ind;
            cin>>ind;
            ind--;
           cout<<a[ind]+query(0,ind,0,n-1,seg)<<endl;
        }else{
            long long  l,r,x;
            cin>>l>>r>>x;
            update(0,0,n-1,x,l-1,r-1,seg);


        }
    }
   
    //cout<<seg[0].first;
    
}