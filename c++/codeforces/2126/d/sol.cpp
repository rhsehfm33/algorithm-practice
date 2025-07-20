#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> a(n);
    for (auto& [l, r, real] : a) {
        cin >> l >> r >> real;
    }
    sort(a.begin(), a.end());

    int ans = k;
    for (auto& [l, r, real] : a) {
        if (ans >= l and ans <= r) {
            ans = max(ans, real);
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