#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getDaysSpent(ll h, ll a, ll b) {
    ll lh = max(0ll, h - a);
    ll result = 1 + (lh + a - b - 1) / (a - b);

    return result;
}

void solve(int _ti) {
    int q;
    cin >> q;

    ll lb = -1, ub = 2e18;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll a, b, n;
            cin >> a >> b >> n;
            ll clb = n - 2 >= 0 ? (a - b) * (n - 2) + a + 1 : 1;
            ll cub = (a - b) * (n - 1) + a;

            if (clb > ub or cub < lb) {
                cout << 0 << ' ';
            }
            else {
                cout << 1 << ' ';
                lb = max(lb, clb);
                ub = min(ub, cub);
            }
        }
        else {
            ll a, b;
            cin >> a >> b;
            ll low = getDaysSpent(lb, a, b);
            ll high = getDaysSpent(ub, a, b);
            if (low != high) {
                cout << -1 << ' ';
            }
            else {
                cout << low << ' ';
            }
        }
    }

    cout << '\n';
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