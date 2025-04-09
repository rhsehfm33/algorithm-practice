#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> d(n);
    for (auto& di : d) {
        cin >> di;
    }

    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = n - 1; i >= 0; --i) {
        ll all = k + 1 + pq.size() * (k + 1);
        if (all <= n - i) {
            ans += d[i];
            pq.push(d[i]);
        } else if (pq.size() and d[i] > pq.top()) {
            ans -= pq.top(); pq.pop();
            ans += d[i];
            pq.push(d[i]);
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