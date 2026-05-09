#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    priority_queue<ll> pq[2];
    for (ll i = 1, ai; i <= n; ++i) {
        cin >> ai;
        ans += ai;
        pq[i & 1].push(ai);
    }
    for (ll i = 0, xi; i < m; ++i) {
        cin >> xi;
        ll d = xi & 1;
        if ((pq[d].size() == n / 2 + (n % 2 and d)) or
        (pq[d].size() and pq[d].top() > 0)) {
            ans -= pq[d].top();
            pq[d].pop();
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