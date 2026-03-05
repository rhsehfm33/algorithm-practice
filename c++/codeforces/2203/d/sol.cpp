#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ac(n + m + 1), as(n + m + 1);
    for (int i = 0, ai; i < n; ++i) {
        cin >> ai;
        ++ac[ai];
    }
    for (int i = 1; i <= n + m; ++i) {
        for (int j = i; ac[i] and j <= n + m; j += i) {
            as[j] += ac[i];
        }
    }

    int bal = 0, turn = 1;
    for (int i = 0, bi; i < m; ++i) {
        cin >> bi;
        if (as[bi] == n) {
            ++bal;
        } else if (as[bi] == 0) {
            --bal;
        } else {
            bal += turn;
            turn *= -1;
        }
    }
    cout << (bal > 0 ? "Alice" : "Bob") << '\n';
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