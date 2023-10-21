#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b + c;

    for (ll i = 3; i <= 6; ++i) {
        if (sum % i || a % (sum / i) || b % (sum / i) || c % (sum / i)) {
            continue;
        } else {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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