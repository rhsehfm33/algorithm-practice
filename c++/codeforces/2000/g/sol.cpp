#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<array<ll, 3>>> vvll3;

int _ti;

bool go(vvll3& u2v, vll& dis, ll s, ll n, ll t0, ll t1, ll t2) {
    fill(dis.begin(), dis.end(), 1e18);
    dis[1] = s;

    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({s, 1});
    while (pq.size()) {
        auto [ud, u] = pq.top(); pq.pop();
        if (dis[u] != ud) {
            continue;
        }
        for (auto [v, l1, l2] : u2v[u]) {
            ll d1 = ud + l1;
            ll d2 = ud + l2;
            if (d1 <= t1 or ud >= t2) {
                if (d1 < dis[v] and d1 <= t0) {
                    dis[v] = d1;
                    pq.push({dis[v], v});
                }
            } else {
                d2 = min(d2, t2 + l1);
                if (d2 < dis[v] and d2 <= t0) {
                    dis[v] = d2;
                    pq.push({dis[v], v});
                }
            }
        }
    }

    return dis[n] <= t0;
}

void solve() {
    ll n, m, t0, t1, t2;
    cin >> n >> m >> t0 >> t1 >> t2;
    vvll3 u2v(n + 1);
    while (m--) {
        ll u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        u2v[u].push_back({v, l1, l2});
        u2v[v].push_back({u, l1, l2});
    }

    vector<ll> dis(n + 1);
    ll low = 0, high = t0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (go(u2v, dis, mid, n, t0, t1, t2)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << low - 1 << '\n';
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