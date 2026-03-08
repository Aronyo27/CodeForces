#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    int original_count = 1;
    vector<int> st;
    set<int> in_st;

    // First element is always original
    st.push_back(a[0]);
    in_st.insert(a[0]);

    for (int i = 1; i < n; i++) {
        // Case 1: Simple continuation
        if (a[i] == a[i-1] + 1) {
            st.push_back(a[i]);
            in_st.insert(a[i]);
        } 
        // Case 2: Jump back to an existing parent in current sequence
        else if (a[i] <= a[i-1] && in_st.count(a[i] - 1)) {
            while (!st.empty() && st.back() != a[i] - 1) {
                in_st.erase(st.back());
                st.pop_back();
            }
            st.push_back(a[i]);
            in_st.insert(a[i]);
        } 
        // Case 3: Must be a new original element
        else {
            original_count++;
            st.clear();
            in_st.clear();
            st.push_back(a[i]);
            in_st.insert(a[i]);
        }
    }

    cout << original_count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}