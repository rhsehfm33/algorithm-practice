#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    multiset<int> ms;

    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (i == 1) {
                ms.insert(a[i][j]);
            }
        }
    }
    ms.insert(a[0][0]);

    vector<int> mn(2 * n + 1, 2 * n + 1);
    mn[*ms.begin()] = *ms.rbegin();
    for (int i = 1; i < n; ++i) {
        ms.insert(a[0][i]);
        ms.erase(ms.find(a[1][i - 1]));
        mn[*ms.begin()] = min(mn[*ms.begin()], *ms.rbegin());
    }

    ll ans = 0;
    for (int i = 2 * n, cmn = 2 * n + 1; i >= 1; --i) {
        cmn = min(cmn, mn[i]);
        if (cmn <= 2 * n) {
            ans += (2 * n - cmn + 1);
        }
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