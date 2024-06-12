#include<bits/stdc++.h>
using namespace std;
 vector<int>ans;
 priority_queue<pair<int,int>>l_max;
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>r_min;
 int ls=0,rs=0;
    void out_Window(int l){
        //fro both just check if top is contain the out of wind if yes the pop all
     while((!l_max.empty())&&(l_max.top().second<=l)){
            l_max.pop();
        }
         while((!r_min.empty())&&(r_min.top().second<=l)){
            r_min.pop();
        }
    }
    void find_Mid(int k){
            //just give left
           
                ans.push_back(l_max.top().first);
               // cout<<"l"<<" "<<ans[l];
        
    }
    void balance(int k){
        //if even k
        if(k%2==0){
            //left is bigger then pop it and push to right
            if(ls>rs){
               r_min.push(make_pair(l_max.top().first,l_max.top().second));
               l_max.pop();
               ls--;
               rs++;
            }else if(rs>ls){
                l_max.push(make_pair(r_min.top().first,r_min.top().second));
                r_min.pop();
               ls++;
               rs--;
            }
            //if equal then no need to balnace in case of even window
        }else{
            //odd window
             if(ls>rs+1){
                //gap is 2 push in right from left and pop from left
               // cout<<"l_max.top()"<<l_max.top().first<<" ";
              r_min.push(make_pair(l_max.top().first,l_max.top().second));
              l_max.pop();
               ls--;
               rs++;
            }else if(rs>ls){
                l_max.push(make_pair(r_min.top().first,r_min.top().second));
               r_min.pop();
               ls++;
               rs--;
            }
            //if ls=rs+1 then no need see pepcode and mik
        }
    }
    void add(int i,int num){
        //int num=nums[i];
        //chcek right is not empty
        if(!r_min.empty()&&r_min.top().first<=num){
            //check if num is greter then right then add in right
             rs++;
             r_min.push(make_pair(num,i));
        }else{
            l_max.push(make_pair(num,i));
            ls++;
        }
    }
    void remove(int l,vector<int>&nums){
        //removing the i-kth elem it is not removing just only dec size
       if((!l_max.empty())&&(nums[l]<=l_max.top().first)){
         ls--;
        }else {
            rs--;
        }
    }
    void medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        //for window till k we add and balance the two side of the pq
        for(i=0;i<k;i++){
            add(i,nums[i]);
            balance(k);
        }
        //now we at k window calculate mid
        find_Mid(k);
        for(i=k;i<n;i++){
            // now we remove i-k th element  which is out of window
             remove(i-k,nums);
             //after removing in pq the elements which are not in window come top of window
             out_Window(i-k);
             //then add ith elemnet 
             add(i,nums[i]);
             //now after add balance the pq
             balance(k);
             //in balance the elemnt can come top which is not in window so pop
             out_Window(i-k);
             //find the mid
             find_Mid(k);
        }
        return ;

    }
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    medianSlidingWindow(arr,k);
    for(auto it:ans)cout<<it<<" ";


}