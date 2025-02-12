#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto& ai : a) {
        cin >> ai;
    }
    a.push_back(2e9);
    for (auto& bi : b) {
        cin >> bi;
    }
    sort(b.begin(), b.end());

    for (ll i = n - 1, j = m - 1; i >= 0; --i) {
        auto bi = lower_bound(b.begin(), b.end(), a[i] + a[i + 1]);
        if (bi != b.end() and *bi == a[i] + a[i + 1]) {
            a[i] = a[i + 1];
        } else {
            if (a[i] <= a[i + 1]) {
                a[i] = bi != b.begin() ? max(a[i], *prev(bi) - a[i]) : a[i];
            } else {
                if (bi == b.begin()) {
                    cout << "NO\n";
                    return;
                } else {
                    a[i] = *prev(bi) - a[i];
                }
            }
        }
    }
    cout << "YES\n";
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