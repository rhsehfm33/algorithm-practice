#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        s.insert(i + 1);
        cin >> p[i];
    }

    int mn = 1e9;
    vector<array<int, 2>> ans;
    for (int i = 0; i < n; ++i) {
        s.erase(p[i]);
        if (p[i] > mn) {
            continue;
        }

        auto it = s.lower_bound(mn + 1);
        if (it != s.end()) {
            ans.push_back({p[i], *it});
        }

        it = s.lower_bound(p[i] + 1);
        while (it != s.end() and *it < mn) {
            ans.push_back({p[i], *it++});
        }
        mn = p[i];
    }

    if (ans.size() < n - 1) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (auto& [u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}