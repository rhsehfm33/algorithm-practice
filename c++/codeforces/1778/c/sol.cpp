#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    string sa = a;
    sort(sa.begin(), sa.end());
    sa.erase(unique(sa.begin(), sa.end()), sa.end());
    k = min(k, (int)sa.size());


    ll ans = 0;
    for (int i = 0; i < (1 << sa.size()); ++i) {
        if (__builtin_popcount(i) != k) {
            continue;
        }
        vector<bool> isIn(128, false);
        for (int j = 0; j < sa.size(); ++j) {
            if ((i >> j) & 1) {
                isIn[sa[j]] = true;
            }
        }

        ll sum = 0;
        for (ll l = 0, r = 0; r < n; ++r) {
            if (isIn[a[r]] or a[r] == b[r]) {
                sum += (r - l + 1);
            }
            else {
                l = r + 1;
            }
        }
        ans = max(ans, sum);
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