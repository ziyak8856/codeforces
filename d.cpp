#include<bits/stdc++.h>
using namespace std;
string clearDigits(string s) {
        int n=s.size();
        int c=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z')st.push(s[i]);
            else st.pop();
        }
        string ans="";
        while(!st.empty()){ans=st.top()+ans; st.pop();}
        
        return ans;
      
        
        
    }
int main(){
     string ans;
     cin>>ans;
     cout<<clearDigits(ans);
}