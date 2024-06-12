#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll
#define endl '\n'
 
const ll mod = 1000000007;
 
bool check = false;
 
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &prevNode)
{
    stack<int> s;
    s.push(node);
    while (!s.empty()){
        int u = s.top();
        s.pop();
        visited[u] = true;
        for (int v : graph[u]){
            if (!visited[v]){
                prevNode[v] = u;
                s.push(v);
            }
            else{
                int _end = u;
                int _start = v;
                vector<int> path;
                path.push_back(_start);
                path.push_back(_end);
                while (_end != _start && _end != -1){
                    _end = prevNode[_end];
                    path.push_back(_end);
                }
                if (path[path.size() - 1] != -1 && path.size() > 3){
                    cout << path.size() << endl;
                    for (int u : path)
                        cout << u << " ";
                    cout << endl;
                    check = true;
                    return;
                }
            }
        }
    }
    cout << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);
    vector<int> prevNode(n + 1, -1);
 
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
 
    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
            dfs(i, graph, visited, prevNode);
        if (check)
            break;
    }
 
    if (!check)
        cout << "IMPOSSIBLE";
 
    return 0;
}