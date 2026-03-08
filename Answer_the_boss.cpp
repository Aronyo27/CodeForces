#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    for(int tt = 1; tt <= t; tt++){
        int n, r;
        cin >> n >> r;

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> rank(n, 1);

        for(int i = 0; i < r; i++){
            int x, y;
            cin >> x >> y;

            // IMPORTANT: reverse edge
            adj[y].push_back(x);
            indegree[x]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                rank[v] = max(rank[v], rank[u] + 1);
                indegree[v]--;

                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<pair<int,int>> ans;
        for(int i = 0; i < n; i++){
            ans.push_back({rank[i], i});
        }

        sort(ans.begin(), ans.end());

        cout << "Scenario #" << tt << ":\n";
        for(auto &p : ans){
            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}
