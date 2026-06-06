#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int _ti;

ll spop(vector<int>& q, int& p, int i) {
    while (q[p] <= i) {
        ++p;
    }
    return q[p];
}

ll ssum(ll s, ll b) {
    return (s + b) * (b - s + 1) / 2;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<vector<int>>> q(2, vector<vector<int>>(n + 2));
    vector<vector<int>> p(2, vector<int>(n + 2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0, xi; j < n; ++j) {
            cin >> xi;
            q[i][xi].push_back(j);
        }
        for (int j = 1; j <= n + 1; ++j) {
            q[i][j].push_back(n);
        }
    }

    ll ans = 0;
    for (ll li = 0, mj = 0; li < n; ++li) {
        ll j = 1;
        for (ll prv = li - 1; j <= n; ++j) {
            if (j > 1 and mj >= j and
            q[0][j][p[0][j]] > prv and q[1][j][p[1][j]] > prv) {
                j = mj;
                break;
            }
            ll ai = spop(q[0][j], p[0][j], prv);
            ll bi = spop(q[1][j], p[1][j], prv);
            prv = min(ai, bi);
            if (ai != bi or prv == n) {
                break;
            }
        }
        ll ri = min(q[0][j][p[0][j]], q[1][j][p[1][j]]);
        ll nli = min(q[0][1][p[0][1]], q[1][1][p[1][1]]);
        ans += ssum(ri - nli, ri - li);
        li = nli;
        mj = j;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}