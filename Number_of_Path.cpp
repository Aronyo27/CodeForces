#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int indegree[N];
long long dp[N];

int main() {
    int n = 6;

    // edges from the picture
    vector<pair<int,int>> edges = {
        {1,2}, {2,3}, {3,6},
        {1,4}, {4,5}, {5,2}, {5,3}
    };

    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        indegree[e.second]++;
    }

    queue<int> q;

    // Topological sort using Kahn
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    dp[1] = 1;  // start node

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            dp[v] += dp[u];   // main transition
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << dp[6] << endl;  // number of paths from 1 to 6
}
