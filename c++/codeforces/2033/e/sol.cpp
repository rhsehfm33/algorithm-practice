#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
        --pi;
    }

    int ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }

        vis[i] = true;
        int cnt = 1, j = i;
        while (!vis[p[j]]) {
            vis[p[j]] = true;
            j = p[j];
            ++cnt;
        }
        ans += (cnt - 1) / 2;
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