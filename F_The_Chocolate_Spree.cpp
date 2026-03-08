#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
vector<int> adj[MAXN];
ll a[MAXN];
ll f[MAXN]; // Max path sum in subtree of u
ll d1[MAXN], d2[MAXN], d3[MAXN]; // Top 3 paths starting at u and going down

void dfs1(int u, int p) {
    d1[u] = a[u];
    d2[u] = 0;
    d3[u] = 0;
    f[u] = a[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        
        ll val = d1[v] + a[u];
        if (val > d1[u]) {
            d3[u] = d2[u];
            d2[u] = d1[u];
            d1[u] = val;
        } else if (val > d2[u]) {
            d3[u] = d2[u];
            d2[u] = val;
        } else if (val > d3[u]) {
            d3[u] = val;
        }
        f[u] = max(f[u], f[v]);
    }
    f[u] = max(f[u], d1[u] + d2[u] - a[u]);
}

ll max_total = 0;

void dfs2(int u, int p, ll up_start, ll up_best) {
    // up_start: max path starting at u going towards parent
    // up_best: max path anywhere in the component above u
    
    if (p != -1) {
        max_total = max(max_total, f[u] + up_best);
    }

    // Prepare top child values to efficiently exclude one child
    vector<pair<ll, int>> child_d, child_f;
    for (int v : adj[u]) {
        if (v == p) continue;
        child_d.push_back({d1[v], v});
        child_f.push_back({f[v], v});
    }
    sort(child_d.rbegin(), child_d.rend());
    sort(child_f.rbegin(), child_f.rend());

    for (int v : adj[u]) {
        if (v == p) continue;

        // Calculate up_start for v
        ll best_d_not_v = up_start;
        if (!child_d.empty()) {
            if (child_d[0].second != v) best_d_not_v = max(best_d_not_v, child_d[0].first + a[u]);
            else if (child_d.size() > 1) best_d_not_v = max(best_d_not_v, child_d[1].first + a[u]);
        }
        ll next_up_start = a[v] + best_d_not_v;

        // Calculate up_best for v
        ll next_up_best = up_best;
        // Case 1: Max path from f[w] where w is a sibling
        if (!child_f.empty()) {
            if (child_f[0].second != v) next_up_best = max(next_up_best, child_f[0].first);
            else if (child_f.size() > 1) next_up_best = max(next_up_best, child_f[1].first);
        }
        // Case 2: Max path through u using up_start and a sibling's d1
        ll d_v1 = up_start, d_v2 = 0;
        int count = 0;
        if (!child_d.empty()) {
            for(auto& p_d : child_d) {
                if(p_d.second == v) continue;
                ll val = p_d.first + a[u];
                if(val > d_v1) { d_v2 = d_v1; d_v1 = val; }
                else if(val > d_v2) { d_v2 = val; }
                if(++count == 2) break;
            }
        }
        next_up_best = max(next_up_best, d_v1 + d_v2 - a[u]);

        dfs2(v, u, next_up_start, next_up_best);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0, 0);

    cout << max_total << endl;

    return 0;
}