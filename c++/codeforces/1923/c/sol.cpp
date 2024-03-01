#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> ps(n + 1), ps1(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> ps[i];
        ps1[i] = (ps[i] == 1) + ps1[i - 1];
        ps[i] += ps[i - 1] - 1;
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll len = (r - l + 1);
        if (ps[r] - ps[l - 1] >= ps1[r] - ps1[l - 1] and len > 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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