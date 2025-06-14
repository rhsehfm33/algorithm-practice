#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    for (ll i = 1; i <= k; i *= 2) {
        for (auto& ai : a) {
            if (k < i) {
                break;
            }
            if (!(ai & i)) {
                ai |= i;
                k -= i;
            }
        }
    }

    ll ans = 0;
    for (auto& ai : a) {
        ans += __builtin_popcountll(ai);
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
