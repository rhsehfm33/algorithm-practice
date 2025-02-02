#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    int kv = a[0];
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (auto& bi : b) {
        cin >> bi;
        if (bi <= kv or bi > a[n - 1]) {
            bi = 0;
        } else {
            bi = a.end() - lower_bound(a.begin(), a.end(), bi);
        }
    }
    sort(b.begin(), b.end());

    for (int k = 1; k <= m; ++k) {
        long long ans = 0;
        for (int i = k - 1; i < m; i += k) {
            ans += b[i] + 1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
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