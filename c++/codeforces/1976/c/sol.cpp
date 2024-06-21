#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

ll sum(vector<ll>& a, vector<ll>& b, ll m) {
    ll s = 0;
    for (ll i = 0; i < a.size(); ++i) {
        if (b[i] > a[i] and m-- > 0) {
            s += b[i];
        } else {
            s += a[i];
        }
    }
    return s;
}

void solve() {
    ll bw = 0, n, m;
    cin >> n >> m;
    ll len = n + m + 1;
    vector<ll> a(len), b(len);
    for (ll i = 0; i < len; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < len; ++i) {
        cin >> b[i];
        bw += b[i] > a[i];
    }

    if (bw <= m) {
        swap(n, m);
        swap(a, b);
    }

    ll ss = sum(a, b, m);
    ll bs = sum(a, b, m + 1);
    for (ll i = 0, cm = 0; i < len; ++i) {
        if (cm <= m and b[i] > a[i]) {
            cout << bs - b[i] << ' ';
            ++cm;
        } else {
            cout << ss - a[i] << ' ';
        }
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