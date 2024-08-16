#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _ti;

void solve() {
    ll n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1, li = 0; i < n; i += 2) {
        if (s[i] == ')') {
            ans += i - li;
            li = i + 1;
        } else {
            ans += 1;
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