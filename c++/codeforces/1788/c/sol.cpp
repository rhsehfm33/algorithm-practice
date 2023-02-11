#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (ll i = 0, n0 = 1, n1 = n / 2 + 2, cur = (1 + 2 * n) - n / 2; i < n; ++i, ++cur) {
        if (i % 2 == 0) {
            cout << n0 << ' ' << cur - n0 << '\n';
            ++n0;
        }
        else {
            cout << n1 << ' ' << cur - n1 << '\n';
            ++n1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int _ti = 1; _ti <= T; ++_ti) {
        solve(_ti);
    }
}