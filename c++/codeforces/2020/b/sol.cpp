#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int _ti;
 
void solve() {
    ll k; cin >> k;
    ll l = 1, h = 2e9;
    while (l <= h) {
        ll m = (l + h) / 2;
        if (m * m - m < k) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    cout << k + l - 1 << '\n';
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