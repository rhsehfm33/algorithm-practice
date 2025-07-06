#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    long long ans = 0;
    for (int r = n - 1; r >= 2; --r) {
        int mn = min(a[r] - a.back(), -a[r]);
        for (int m = r - 1, l = 0; l < m; --m) {
            while (l < m and a[l] + a[m] + mn <= 0) {
                ++l;
            }
            ans += (m - l);
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