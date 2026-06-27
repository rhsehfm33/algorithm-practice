#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (auto& hi : h) {
        cin >> hi;
    }

    vector<ll> mx(n);
    for (ll i = 0; i < n; ++i) {
        ll ans = 0;
        mx[n - 1] = h[n - 1];
        for (ll j = n - 2; j >= 0; --j) {
            mx[j] = max(h[j], mx[j + 1]);
        }
        for (ll j = 1, v = 0; j < n; ++j) {
            ll cv = min(h[j - 1], mx[j]);
            if (v > mx[j]) {
                v = cv;
            } else {
                v = max(v, cv);
            }
            ans += v;
        }
        cout << ans << ' ';
        h.push_back(h.front());
        h.erase(h.begin());
        fill(mx.begin(), mx.end(), 0);
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