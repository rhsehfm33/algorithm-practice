#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), pi2i(n + 1), vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pi2i[p[i]] = i;
    }

    int ans = 0;
    int d = n;
    while (d--) {
        int di;
        cin >> di;
        while (!vis[di]) {
            ++ans;
            vis[di] = true;
            di = pi2i[di];
        }
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
        cout << '\n';
    }

    return 0;
}