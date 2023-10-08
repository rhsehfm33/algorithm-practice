#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n;
    cin >> n;

    ll mx = -2e9, os = 0, es = 0;
    for (ll i = 0; i < n; ++i) {
        ll ci;
        cin >> ci;
        mx = max(mx, ci);
        if (ci <= 0) {
            continue;
        }

        if (i % 2) {
            os += ci;
        }
        else {
            es += ci;
        }
    }

    if (mx < 0) {
        cout << mx << '\n';
    }
    else {
        cout << max(os, es) << '\n';
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