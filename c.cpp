#include<bits/stdc++.h>
using namespace std;
int findWinningPlayer(vector<int>& arr, int k) {
        deque<int>q;
        int n=arr.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            q.push_back(i);
            mx=max(arr[i],mx);
    
        }

        unordered_map<int,int>mp;
        while(true){
            int one=q.front();
            q.pop_front();
            int two=q.front();
            q.pop_front();
            if(arr[one]>arr[two]){
                q.push_front(one);
                mp[one]++;
                if(arr[one]==mx)return one;
                if(mp[one]==k)return one;
                q.push_back(two);
            }else{
                q.push_front(two);
                mp[two]++;
                 if(arr[two]==mx)return two;
                if(mp[two]==k)return two;
                q.push_back(one);
            }
        }
        return -1;
    }
int main(){
   vector<int>skills = {16,4,7,17};
     int k =562084119;
     cout<<findWinningPlayer(skills,k);
}