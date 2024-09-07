#include <bits/stdc++.h>

using namespace std;

int _ti;

array<int, 26> add(array<int, 26> a, array<int, 26> b) {
    for (int i = 0; i < 26; ++i) {
        a[i] += b[i];
    }
    return a;
}

int count(array<int, 26> a) {
    return accumulate(a.begin(), a.end(), 0) - *max_element(a.begin(), a.end());
}

void solve() {
    int n; cin >> n;
    string s; cin >> s; s = "!!" + s;
    vector<array<int, 26>> ls(n + 4), rs(n + 4);
    for (int i = 2; i <= n + 1; ++i) {
        ++ls[i][s[i] - 'a'];
        for (int j = 0; j < 26; ++j) {
            ls[i][j] += ls[i - 2][j];
        }
    }
    for (int i = n + 1; i >= 2; --i) {
        ++rs[i][s[i] - 'a'];
        for (int j = 0; j < 26; ++j) {
            rs[i][j] += rs[i + 2][j];
        }
    }

    int ans = n % 2 ? 1e9 : count(ls[n + 1]) + count(ls[n]);
    for (int i = 2; i <= n + 1 and n % 2; ++i) {
        int oc = count(add(ls[i - 1], rs[i + 2]));
        int ec = count(add(ls[i - 2], rs[i + 1]));
        ans = min(ans, 1 + oc + ec);
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