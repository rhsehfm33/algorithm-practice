#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }

    multiset<int> ls, rs;
    for (int i = n - 1; i > 0; --i) {
        rs.insert(a[i] + i);
    }
    
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            rs.erase(rs.find(a[i] + i));
        }
        int l = ls.size() ? *ls.rbegin() : a[0];
        int r = rs.size() ? *rs.rbegin() : a[n - 1];
        ans = min(ans, max({a[i], l, r}));
        if (i < n - 1) {
            ls.insert(a[i] + n - i - 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}