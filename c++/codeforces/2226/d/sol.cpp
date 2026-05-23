#include <bits/stdc++.h>
using namespace std;

int _ti;

bool is_ok(vector<int>& a, int mx, int mn) {
    if (a.empty()) {
        return true;
    }

    for (int i = 1, cmx = a[0]; i < a.size(); ++i) {
        if (a[i] < cmx and mn > a[i] and mx < cmx) {
            return false;
        }
        cmx = max(cmx, a[i]);
    }
    return true;
}

void solve() {
    int mx[2] = {0, 0};
    int mn[2] = {112345, 112345};

    int n;
    cin >> n;
    vector<int> a[2];
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        a[ai % 2].push_back(ai);
        mn[ai % 2] = min(mn[ai % 2], ai);
        mx[ai % 2] = max(mx[ai % 2], ai);
    }
    if (is_ok(a[0], mx[1], mn[1]) and is_ok(a[1], mx[0], mn[0])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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