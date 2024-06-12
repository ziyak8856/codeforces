#include<bits/stdc++.h>
using namespace std;
int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};
void dfs(int i,int j,int &c,vector<vector<int>>&lables,vector<vector<char>>&a,int &n,int &m,int &label){
    a[i][j]='.';
    lables[i][j]=label;
    c++;
    for(int k=0;k<4;k++){
      int nr=dr[k]+i;
      int nc=dc[k]+j;
      if(nc>=0&&nr>=0&&nc<m&&nr<n&&a[nr][nc]=='#'){
        dfs(nr,nc,c,lables,a,n,m,label);
      }
    }
}
int main(){
   int t;
   cin>>t;
   while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    map<int,int>mp;
    vector<vector<int>>lables(n,vector<int>(m,0));
    int label=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='#'){
               int c=0;
               dfs(i,j,c,lables,a,n,m,label);
               mp[label]=c;
               label++;
            }
        }
    }

    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<lables[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    vector<int>colsum(m);
    vector<int>rowsum(n);
    for(int i=0;i<n;i++){
        set<int>st;
        int sum=0;
        for(int j=0;j<m;j++){
            if(lables[i][j]!=0){
                st.insert(lables[i][j]);
            }else{
              sum++;
              if(i-1>=0&&lables[i-1][j]!=0){
                st.insert(lables[i-1][j]);
              }
              if(i+1<n&&lables[i+1][j]!=0){
                st.insert(lables[i+1][j]);
              }
              
            }
        }
        for(auto it:st){
            sum+=mp[it];
        }
        rowsum[i]=sum;

    }
    for(int j=0;j<m;j++){
        set<int>st;
        int sum=0;
        for(int i=0;i<n;i++){
            if(lables[i][j]!=0){
                st.insert(lables[i][j]);
            }else{
              sum++;
              if(j-1>=0&&lables[i][j-1]!=0){
                st.insert(lables[i][j-1]);
              }
              if(j+1<m&&lables[i][j+1]!=0){
                st.insert(lables[i][j+1]);
              }
              
            }
        }
        for(auto it:st){
            sum+=mp[it];
        }
        colsum[j]=sum;

    }
    sort(rowsum.begin(),rowsum.end());
    for(auto it:rowsum)cout<<it<<" ";
    cout<<endl;
    sort(colsum.begin(),colsum.end());
    for(auto it:colsum)cout<<it<<" ";
    cout<<endl;


    
    
   
   }
    
   
}