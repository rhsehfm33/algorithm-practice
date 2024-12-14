#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<set<int>> s(3);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[a[i]].insert(i);
    }

    vector<array<int, 2>> ans;
    for (int i = n; i >= 1; --i) {
        s[a[i]].erase(i);
        for (int j = 1; j <= 2; ++j) {
            if (j > a[i] and s[j].size()) {
                ++a[i];
                --a[*s[j].begin()];
                ans.push_back({*s[j].begin(), i});
                s[j - 1].insert(*s[j].begin());
                s[j].erase(s[j].begin());
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
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