#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getDistance(array<ll, 2> xy1, array<ll, 2> xy2) {
    return abs(xy1[0] - xy2[0]) + abs(xy1[1] - xy2[1]);
}

void solve(int _ti) {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    --a; --b;

    vector<array<ll, 2>> xys(n);
    for (int i = 0; i < n; ++i) {
        cin >> xys[i][0] >> xys[i][1];
    }

    ll ans = getDistance(xys[a], xys[b]);
    ll min1 = a < k ? 0 : 1e10;
    ll min2 = b < k ? 0 : 1e10;
    for (int i = 0; i < k; ++i) {
        if (i != a) {
            min1 = min(min1, getDistance(xys[i], xys[a]));
        }
        if (i != b) {
            min2 = min(min2, getDistance(xys[i], xys[b]));
        }
    }
    ans = min(ans, min1 + min2);

    cout << ans << '\n';
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