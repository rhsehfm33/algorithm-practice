#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int gcd_extended(int a, int b, int* x, int* y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcd_extended(b % a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    gcd_extended(a, m, &x, &y);
    int res = (x % m + m) % m;
    return res;
}

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    map<int, int> ai2cnt;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++ai2cnt[ai];
    }

    if (ai2cnt.size() < m) {
        cout << 0 << '\n';
        return;
    }

    int cur_mul = 1;
    vector<pair<int, int>> aicnt(ai2cnt.begin(), ai2cnt.end());
    for (int i = 0; i < m; ++i) {
        cur_mul = ((ll)cur_mul * aicnt[i].second) % MOD;
    }

    int ans = 0;
    if (aicnt[m - 1].first - aicnt[0].first == m - 1) {
        ans = (ans + cur_mul) % MOD;
    }

    for (int ai = m; ai < ai2cnt.size(); ++ai) {
        cur_mul = ((ll)cur_mul * aicnt[ai].second) % MOD;
        cur_mul = ((ll)cur_mul * mod_inverse(aicnt[ai - m].second, MOD)) % MOD;
        if (aicnt[ai].first - aicnt[ai - m + 1].first == m - 1) {
            ans = (ans + cur_mul) % MOD;
        }
    }

    cout << ans << '\n';
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