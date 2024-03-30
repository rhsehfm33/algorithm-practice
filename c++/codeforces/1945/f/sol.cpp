#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void move(set<array<ll, 2>>& s, set<array<ll, 2>>& t) {
    t.insert(*s.rbegin());
    s.erase(prev(s.end()));
}

void solve() {
    ll n, mx = 0, k = 1;
    cin >> n;
    vector<ll> v(n + 1);
    set<array<ll, 2>> s, t;
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
        s.insert({v[i], i});
    }
    move(s, t);
    mx = t.begin()->at(0);
    
    for (ll i = 1, pi; i <= n; ++i) {
        cin >> pi;
        if (i >= (n + 1) / 2) {
            continue;
        }
        if (s.count({v[pi], pi})) {
            s.erase({v[pi], pi});
        } else {
            t.erase({v[pi], pi});
        }
        while (t.size() <= i) {
            move(s, t);
        }

        ll cur = t.begin()->at(0) * (i + 1);
        if (cur > mx) {
            mx = cur;
            k = i + 1;
        }
    }
    cout << mx << ' ' << k << '\n';
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