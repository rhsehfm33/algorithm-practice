#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << 0 << '\n';
    }
    else if (n == 1) {
        cout << 2 << '\n';
    }
    else {
        cout << min(n + 1, m) << '\n';
    }
    
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if ((m - 1 - i + j + n * m) % m == j) {
                cout << (m - i + j + n * m) % m << ' ';
            }
            else {
                cout << (m - 1 - i + j + n * m) % m << ' ';
            }
        }
        cout << '\n';
    }
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