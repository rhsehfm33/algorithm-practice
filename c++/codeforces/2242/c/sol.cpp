#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> sa;
    for (int i = 0, ai = 0, pai = 0; i < n; ++i) {
        cin >> ai;
        if (ai == pai) {
            ++sa.back();
        } else {
            sa.push_back(1);
            pai = ai;
        }
    }
    sort(sa.begin(), sa.end(), greater<int>());

    int ans = 0, prv = 0, psz = sa.size();
    while (sa.size()) {
        n -= (sa.back() - prv) * (int)sa.size();
        prv = sa.back();
        psz = sa.size();
        while (sa.size() and sa.back() == prv) {
            sa.pop_back();
        }
        if ((k - n) >= psz and (k - n) % psz == 0) {
            ++ans;
        }
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