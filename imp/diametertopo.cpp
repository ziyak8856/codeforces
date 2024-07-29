#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/

 int mx=0;
    int bfs(vector<vector<int>>&edges){
        int n=edges.size(),currdia=0;
        vector<int>deg(n+1,0);
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            deg[edges[i][0]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            deg[edges[i][1]]++;
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        int level=0;
        
        for(int i=0;i<=n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }

        while(q.size()>1){
            level++;
            int m=q.size();
            for(int i=0;i<m;i++){
                int temp=q.front();
                deg[temp]=0;
                q.pop();
                for(auto it:adj[temp]){
                    deg[it]--;
                    if(deg[it]==1){
                        q.push(it);
                    }
                }
            }
        }

        //odd len so even diameter lenght
        if(q.size()==1){
            currdia=level*2; 
        }
        else{
            currdia=level*2-1; 
        }
        mx=max(currdia,mx);
        return level;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        return max(bfs(edges1)+bfs(edges2)+1,mx);
    }
int main() {
   vector<vector<int>>edges1={{0,1},{0,3},{0,2}};
   vector<vector<int>>edges2={{0,1}};
   cout<<minimumDiameterAfterMerge(edges1,edges2);
}