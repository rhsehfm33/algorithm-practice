#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> sv = {1};
    vector<set<int>> u2v(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u2v[u].insert(v);
        u2v[v].insert(u);
        sv.push_back(i + 2);
    }
    sort(sv.begin(), sv.end(), [&](int lv, int rv) {
        return u2v[lv].size() > u2v[rv].size();
    });

    int ans = 0, mx1 = 0, mx2 = 0, mx0 = u2v[sv[0]].size();
    for (int i = 1; i < n; ++i) {
        int mx = u2v[sv[i]].size();
        if (u2v[sv[0]].count(sv[i])) {
            ans = max(ans, mx0 + mx - 2);
            if (mx > mx1) {
                mx2 = mx1;
                mx1 = mx;
            } else if (mx > mx2) {
                mx2 = mx;
            }
        } else {
            ans = max(ans, mx0 + mx - 1);
            break;
        }
    }
    ans = max(ans, mx1 + mx2 - 1);
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