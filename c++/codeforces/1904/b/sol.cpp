#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;
    vector<array<ll, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());

    vector<ll> ans(n);
    for (ll li = 0, ri = 0, sum = 0; li < n; ++li) {
        while (ri <= li or (ri < n and sum >= a[ri][0])) {
            sum += a[ri++][0];
        }
        ans[a[li][1]] = ri - 1;
    }

    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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