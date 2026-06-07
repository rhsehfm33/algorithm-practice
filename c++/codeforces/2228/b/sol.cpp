#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

void solve() {
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if (n <= 3) {
        cout << "1\n";
        return;
    }
    ll d1 = (x1 - x2 + n) % n;
    ll d2 = (x2 - x1 + n) % n;
    cout << k + min(d1, d2) << '\n';
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