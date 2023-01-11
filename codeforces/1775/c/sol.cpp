#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, x;
    cin >> n >> x;

    ll m = n;
    while (m < (ll)2e18) {
        if (((m & n) & x) != x) {
            cout << "-1\n";
            return;
        }
        if ((m & n) == x) {
            cout << m << '\n';
            return;
        }
        m += m & -m;
    }

    cout << "-1\n";
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