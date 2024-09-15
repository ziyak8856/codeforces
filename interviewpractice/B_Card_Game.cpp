#include<bits/stdc++.h>
using namespace std;
class solve{
    private:
    priority_queue<int>pq;
    int a[4]={1,2,6,8};
    public:
    void set(int x){
        this->a[0]=x;
    }
    int large(){
        for(int i=0;i<4;i++)pq.push(a[i]);
        return pq.top();
    }
};
int main(){
    int t;
    cin>>t;
    solve solution;
    solution.set(10);
    cout<<solution.large();
    
}