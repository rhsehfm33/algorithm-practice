#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int _ti;
 
void solve() {
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
 
    vector<ll> mx;
    for (ll j = n; j > 0; --j) {
        ll c1 = 0;
        for (ll i = 0; i < n; ++i) {
            c1 += (a[i][n] - a[i][j - 1] == n - j + 1);
        }
 
        if (mx.size()) {
            mx.push_back(min(c1, mx.back() - 1));
        } else {
            mx.push_back(c1);
        }
        if (mx.back() == 0) {
            mx.pop_back();
            break;
        }
    }
 
    cout << min(n, (int)mx.size() + 1) << '\n';
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