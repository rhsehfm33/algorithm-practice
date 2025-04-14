#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int _ti;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    ll g = 0;
    for (ll i = 1; i < n; ++i) {
        if (a[i] % a[0] == 0) {
            g = gcd(g, a[i]);
        }
    }
    cout << (g == a[0] ? "Yes\n" : "No\n");
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