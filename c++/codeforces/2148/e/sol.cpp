#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    map<int, int> m1;

    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ++m1[ai];
    }

    ll ans = 0;
    map<int, int> m2;
    for (ll l = 0, r = 0; r < n; ++r) {
        if (m1[a[r]] % k) {
            cout << "0\n";
            return;
        }

        ++m2[a[r]];
        while (m2[a[r]] > m1[a[r]] / k) {
            --m2[a[l++]];
        }
        ans += (r - l + 1);
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