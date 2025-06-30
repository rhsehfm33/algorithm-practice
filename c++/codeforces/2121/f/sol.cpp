#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void solve() {
    ll n, s, x;
    cin >> n >> s >> x;
    vector<ll> a(n + 1), ps(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        ps[i] = a[i] + ps[i - 1];
    }

    ll ans = 0;
    map<ll, ll> cnt;
    cnt[0] = 1;
    for (ll li = 1, mi = 1, ri = 1; ri <= n; ++ri) {
        if (a[ri] > x) {
            cnt.clear();
            cnt[0] = 1;
            li = mi = ri + 1;
            continue;
        }
        if (a[ri] == x) {
            while (mi < ri) {
                ++cnt[ps[mi] - ps[li - 1]];
                ++mi;
            }
        }
        if (a[mi] != x) {
            continue;
        }
        ll cs = (ps[ri] - ps[li - 1]) - s;
        if (cnt.count(cs)) {
            ans += cnt[cs];
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