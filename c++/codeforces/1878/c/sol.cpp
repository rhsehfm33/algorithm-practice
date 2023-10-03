#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, k, x;
    cin >> n >> k >> x;
    ll mn = (1 + k) * k / 2;
    ll mx = (n - k + 1 + n) * k / 2;
    if (mn <= x and x <= mx) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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