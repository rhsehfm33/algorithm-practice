#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 2>> ab(n);
    for (ll i = 0; i < 2; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> ab[j][i];
        }
    }
    sort(ab.begin(), ab.end(), [](auto& l, auto& r) {
        ll ld = l[0] - l[1];
        ll rd = r[0] - r[1];
        if (ld != rd) {
            return ld < rd;
        } else {
            return l[0] > r[0];
        }
    });

    map<ll, ll> cnt;
    priority_queue<ll> pq;
    for (int i = 0, ci; i < m; ++i) {
        cin >> ci;
        if (!cnt[ci]) {
            pq.push(ci);
        }
        ++cnt[ci];
    }

    ll ans = 0, abi = 0;
    while (pq.size()) {
        ll cur = pq.top(); pq.pop();
        while (abi < ab.size() and ab[abi][0] > cur) {
            ++abi;
        }
        if (abi < ab.size()) {
            ll cost = ab[abi][0] - ab[abi][1];
            ll next = ab[abi][1] + (cur - ab[abi][0]) % cost;
            ll added = ((cur - next) / cost) * cnt[cur] * 2;
            ans += added;
            if (!cnt[next]) {
                pq.push(next);
            }
            cnt[next] += cnt[cur];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}