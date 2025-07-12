#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    int mx = (n % p ? m : n / p * q);
    int mn = (n % p ? 0 : n / p * q);
    cout << (m >= mn and m <= mx ? "YES\n" : "NO\n");
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