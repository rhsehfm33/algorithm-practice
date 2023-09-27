#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

void solve(int _ti) {
    string s;
    cin >> s;

    ll ans1 = 0, ans2 = 1, i = 0, j = 0;
    while (i < s.size()) {
        while (j < s.size() and s[i] == s[j]) {
            ++j;
        }

        if (j - i > 1) {
            ans1 += (j - i - 1);
            ans2 = (ans2 * (j - i)) % MOD;
        }
        i = j;
    }

    for (ll k = 1; k <= ans1; ++k) {
        ans2 = (ans2 * k) % MOD;
    }

    cout << ans1 << ' ' << ans2 << '\n';
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