#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, m, k;
    cin >> n >> m >> k;
    if (k == 1) {
        cout << 1 << '\n';
    }
    else if (k == 2) {
        cout << min(m, n - 1) + m / n << '\n';
    }
    else if (k == 3) {
        if (m <= n) {
            cout << 0 << '\n';
        }
        else {
            cout << (m / n - 1) * (n - 1) + m % n << '\n';
        }
    }
    else {
        cout << 0 << '\n';
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