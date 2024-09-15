#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n+1,0);
    vector<vector<int>>rounds={{1,2,10},{2,4,5},{3,5,12}};
    int m=rounds.size();
    for(int i=0;i<m;i++){
        int s=rounds[i][0];
        int e=rounds[i][1];
        int val=rounds[i][2];
        a[s-1]+=val;
        a[e]-=val;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];

    }
    cout<<*max_element(a.begin(),a.end());
}