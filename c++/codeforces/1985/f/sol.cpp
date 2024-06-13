#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), c(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& ci : c) {
        cin >> ci;
    }

    ll low = 1, high = 1e11;
    while (low <= high) {
        ll ch = h;
        ll mid = (low + high) / 2;
        for (ll i = 0; i < n and ch > 0; ++i) {
            ch -= a[i] * ((mid + c[i] - 1) / c[i]);
        }
        if (ch <= 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << high + 1 << '\n';
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