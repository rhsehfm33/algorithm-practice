#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }

    vector<array<int, 2>> bc(m), bc0, bc1;
    for (auto& [b, c] : bc) {
        cin >> b;
    }
    for (auto& [b, c] : bc) {
        cin >> c;
        if (c) {
            bc1.push_back({b, c});
        } else {
            bc0.push_back({b, c});
        }
    }

    int ans = 0;
    sort(bc1.begin(), bc1.end());
    for (auto& [b, c] : bc1) {
        auto it = a.lower_bound(b);
        if (it == a.end()) {
            break;
        }
        ++ans;
        a.insert(max(*it, c));
        a.erase(it);
    }

    sort(bc0.begin(), bc0.end());
    for (auto& [b, c] : bc0) {
        auto it = a.lower_bound(b);
        if (it == a.end()) {
            break;
        }
        ++ans;
        a.erase(it);
    }

    cout << ans << '\n';
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