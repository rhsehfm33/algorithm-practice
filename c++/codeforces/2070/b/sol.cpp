#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    string s;
    ll n, x, k, ans = 0, i = 0, pi = -1;
    cin >> n >> x >> k >> s;
    while (k-- > 0 and i < n) {
        x += (s[i] == 'L' ? -1 : 1);
        if (x == 0) {
            ++ans;
            if (i == pi) {
                ans += k / (i + 1);
                break;
            }
            pi = i;
            i = 0;
        } else {
            ++i;
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