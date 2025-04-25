#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<array<ll, 2>> cnt(30);
    for (auto& ai : a) {
        cin >> ai;
        for (ll i = 0; i < 30; ++i) {
            ++cnt[i][(ai >> i) & 1];
        }
    }

    ll ans = 0;
    for (auto& ai : a) {
        ll cur = 0;
        for (ll i = 0; i < 30; ++i) {
            ll c = cnt[i][((ai >> i) & 1) ^ 1];
            cur += (1LL << i) * c;
        }
        ans = max(ans, cur);
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