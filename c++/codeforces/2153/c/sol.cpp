#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ++m[ai];
    }

    ll oc = 0, ec = 0, es = 0;
    vector<ll> o;
    for (auto [ai, cnt] : m) {
        es += ai * cnt;
        ec += cnt;
        if (cnt % 2) {
            o.push_back(ai);
            oc += 1;
            es -= ai;
            ec -= 1;
        }
    }

    ll ans = ec >= 4 ? es : 0;
    for (ll i = 0; i < o.size(); ++i) {
        if (es > o[i]) {
            ans = max(ans, o[i] + es);
        }
        if (i + 1 < o.size() and es + o[i] > o[i + 1]) {
            ans = max(ans, es + o[i] + o[i + 1]);
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