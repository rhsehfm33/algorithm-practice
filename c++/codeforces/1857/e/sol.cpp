#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<array<ll, 2>> x(n);
    for (ll i = 0; i < n; ++i) {
        x[i][0] = i;
        cin >> x[i][1];
    }
    sort(x.begin(), x.end(), [](auto& l, auto& r) {
        return l[1] < r[1];
    });

    vector<ll> ls(n), rs(n);
    for (ll i = 0; i < n; ++i) {
        if (i == 0) {
            ls[i] = x[i][1];
        }
        else {
            ls[i] = ls[i - 1] + x[i][1];
        }
    }
    for (ll i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            rs[i] = x[i][1];
        }
        else {
            rs[i] = rs[i + 1] + x[i][1];
        }
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        ll target = x[i][1];
        ll l = target * (i + 1) - ls[i] + (i + 1);
        ll r = i + 1 >= n ? 0 : rs[i + 1] - target * (n - (i + 1)) + (n - (i + 1));
        ans[x[i][0]] = l + r;
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}