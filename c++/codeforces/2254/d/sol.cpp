#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, mx = 0, z = 0;
    cin >> n;
    vector<array<ll, 2>> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i][0];
        b[i][1] = i;
        z += (b[i][0] == 0);
    }
    if (z == 0) {
        cout << "-1\n";
        return;
    }
    sort(b.begin(), b.end());

    vector<ll> a(n);
    for (ll i = 0, j = 0; j < n;) {
        while (j < n and b[i][0] == b[j][0]) {
            ++j;
        }
        if (j >= n) {
            break;
        }
        if ((b[j][0] - b[i][0]) % (j - i)) {
            cout << "-1\n";
            return;
        }
        ll val = (b[j][0] - b[i][0]) / (j - i);
        if (val <= mx) {
            cout << "-1\n";
            return;
        }
        mx = val;
        while (i < j) {
            a[b[i++][1]] = val;
        }
    }
    for (auto ai : a) {
        cout << (ai ? ai : mx + 1) << ' ';
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