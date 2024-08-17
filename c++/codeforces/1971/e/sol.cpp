#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int _ti;
 
void solve() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(k + 1), b(k + 1);
    for (ll i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i <= k; ++i) {
        cin >> b[i];
    }
 
    while (q--) {
        ll d;
        cin >> d;
        ll ti = lower_bound(a.begin() + 1, a.end(), d) - a.begin() - 1;
        ll ans = b[ti] + ((d - a[ti]) * (b[ti + 1] - b[ti])) / (a[ti + 1] - a[ti]);
        cout << ans << ' ';
    }
    cout << '\n';
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