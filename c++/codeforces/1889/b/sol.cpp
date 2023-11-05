#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n), sa;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) {
            sa.push_back(i);
        }
    }

    sort(sa.begin(), sa.end(), [&](ll l, ll r) {
        return a[l] - (l + 1) * c > a[r] - (r + 1) * c;
    });

    ll sum = a[0];
    for (ll i = 0; i < sa.size(); ++i) {
        sum += a[sa[i]];
        if (sum < (sa[i] + 1) * c) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}