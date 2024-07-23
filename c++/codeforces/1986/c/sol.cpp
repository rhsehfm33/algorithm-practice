#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    string s, c;
    int n, m;
    cin >> n >> m >> s;
    set<int> ind;
    for (int i = 0, indi = 0; i < m; ++i) {
        cin >> indi;
        ind.insert(--indi);
    }
    cin >> c;
    sort(c.begin(), c.end());

    int ci = 0;
    for (auto& indi : ind) {
        s[indi] = c[ci++];
    }
    cout << s << '\n';
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