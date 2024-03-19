#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll _ti;
 
ll get_max(vector<ll>& a) {
    ll mi = 1;
    for (ll i = 0; i < a.size() - 1; ++i) {
        if (a[mi] - a[mi - 1] < a[i + 1] - a[i]) {
            mi = i + 1;
        }
    }
    return mi;
}
 
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), d(m), f(k);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& di : d) {
        cin >> di;
    }
    for (auto& fi : f) {
        cin >> fi;
    }
 
    sort(d.begin(), d.end());
    sort(f.begin(), f.end());
 
    ll mi = get_max(a);
    ll mn = a[mi] - a[mi - 1];
    ll mid = (a[mi] + a[mi - 1]) / 2;
    for (ll i = 0; i < m; ++i) {
        ll fi = lower_bound(f.begin(), f.end(), mid - d[i]) - f.begin();
        if (fi != k) {
            ll dfm = d[i] + f[fi];
            if (dfm >= a[mi - 1] and dfm <= a[mi]) {
                mn = min(mn, max(a[mi] - dfm, dfm - a[mi - 1]));
            }
        }
        if (fi != 0) {
            ll dfm = d[i] + f[fi - 1];
            if (dfm >= a[mi - 1] and dfm <= a[mi]) {
                mn = min(mn, max(a[mi] - dfm, dfm - a[mi - 1]));
            }
        }
    }
 
    a.insert(lower_bound(a.begin(), a.end(), a[mi - 1] + mn), a[mi - 1] + mn);
    ll ansi = get_max(a);
    cout << a[ansi] - a[ansi - 1] << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    ll T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }
 
    return 0;
}