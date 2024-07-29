#include <bits/stdc++.h>
using namespace std;

// A class that represents an undirected graph
class Graph {
    int V; // No. of vertices
    list<int> *adj; // A dynamic array of adjacency lists
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent, vector<pair<int, int>>& bridges);

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void removeEdge(int v, int w); // to remove an edge from the graph
    void bridge(vector<pair<int, int>>& bridges); // stores all bridges
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Note: the graph is undirected
}

void Graph::removeEdge(int v, int w) {
    adj[v].remove(w);
    adj[w].remove(v);
}

// A recursive function that finds and stores bridges using DFS traversal
void Graph::bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent, vector<pair<int, int>>& bridges) {
    static int time = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (v == parent)
            continue;

        if (!visited[v]) {
            bridgeUtil(v, visited, disc, low, u, bridges);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                bridges.push_back({u, v});
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

// Function to find all bridges and store them in a vector
void Graph::bridge(vector<pair<int, int>>& bridges) {
    vector<bool> visited(V, false);
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    int parent = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            bridgeUtil(i, visited, disc, low, parent, bridges);
    }
}

// Union-Find Data Structure
class UnionFind {
    vector<int> parent, rank, size;

public:
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v])
                swap(u, v);
            parent[v] = u;
            if (rank[u] == rank[v])
                rank[u]++;
            size[u] += size[v];
        }
    }

    int getSize(int u) {
        return size[find(u)];
    }

    void reset(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
};

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Graph g(n + 1);
        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g.addEdge(x, y);
        }

        vector<pair<int, int>> bridges;
        g.bridge(bridges);

        int minPairs = INT_MAX;

        for (auto bridge : bridges) {
            int u = bridge.first;
            int v = bridge.second;

            // Reset Union-Find
            UnionFind uf(n + 1);
            for (int i = 0; i < m; i++) {
                if (make_pair(x, y) != bridge) {
                    uf.unionSets(x, y);
                }
            }

            // Calculate the number of pairs in all components
            unordered_map<int, int> componentSize;
            for (int i = 1; i <= n; i++) {
                int root = uf.find(i);
                componentSize[root] = uf.getSize(root);
            }

            int pairs = 0;
            for (auto& comp : componentSize) {
                int size = comp.second;
                pairs += (size * (size - 1)) / 2;
            }
            minPairs = min(minPairs, pairs);
        }

        minPairs = (minPairs == INT_MAX) ? (n * (n - 1)) / 2 : minPairs;
        cout << minPairs << endl;
    }

    return 0;
}
