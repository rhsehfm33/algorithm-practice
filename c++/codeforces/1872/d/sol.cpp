#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    ll n, x, y;
    cin >> n >> x >> y;

    ll d1 = n / x - n / lcm(x, y);
    ll d2 = n / y - n / lcm(x, y);
    ll sum1 = (n + n - d1 + 1) * d1 / 2;
    ll sum2 = (1 + d2) * d2 / 2;
    cout << sum1 - sum2 << '\n';
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