#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll low = 1, high = n;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll p1 = min(mid * 2, (n + 6) / 7) * t;
        ll p2 = mid * l;
        if (p1 + p2 >= p) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << n - (high + 1) << '\n';
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