#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }

    ll ans = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int al = 0, ar = n - 1, bl = 0, br = m - 1; al <= ar;) {
        ll r1 = abs(a[al] - b[br]);
        ll r2 = abs(a[ar] - b[bl]);
        if (r1 >= r2) {
            ans += r1;
            ++al;
            --br;
        } else {
            ans += r2;
            --ar;
            ++bl;
        }
    }
    cout << ans << '\n';
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