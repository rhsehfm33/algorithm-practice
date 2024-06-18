#include <bits/stdc++.h>

using namespace std;

int _ti;

typedef long long ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n + 1);
    for (ll i = 0; i <= n; ++i) {
        p[i] = i;
    }

    for (ll l = 1, r = n; l < r and k > 0; ++l, --r) {
        while (r > l and 2 * (p[r] - p[l]) > k) {
            --r;
        }
        if (l < r) {
            k -= 2 * (p[r] - p[l]);
            swap(p[r], p[l]);
        }
    }

    if (k) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (ll i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
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