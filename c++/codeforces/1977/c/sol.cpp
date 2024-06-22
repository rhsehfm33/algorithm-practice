#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

set<ll> getFactors(ll alcm) {
    set<ll> s;
    for (ll i = 1; i * i <= alcm; ++i) {
        if (alcm % i == 0) {
            s.insert(i);
            s.insert(alcm / i);
        }
    }
    return s;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    ll alcm = 1;
    for (auto& ai : a) {
        alcm = lcm(alcm, ai);
        if (alcm > 1e9) {
            cout << n << '\n';
            return;
        }
    }

    ll ans = 0;
    set<ll> f = getFactors(alcm);
    for (auto& fi : f) {
        ll clcm = 1, len = 0;
        for (auto& ai : a) {
            if (fi == ai) {
                clcm = 0;
                break;
            }
            if (fi % ai == 0) {
                clcm = lcm(clcm, ai);
                ++len;
            }
        }
        if (clcm == fi) {
            ans = max(ans, len);
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