#include <bits/stdc++.h>
using namespace std;

int _ti;
const int MOD = 998244353;
vector<int> ps;

void preset() {
    for (int i = 0, j = 1; i < 100005; ++i, j = (j * 2) % MOD) {
        ps.push_back(j);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto& pi : p) {
        cin >> pi;
    }
    for (auto& qi : q) {
        cin >> qi;
    }

    for (int i = 0, pi = 0, qi = 0; i < n; ++i) {
        if (p[i] > p[pi]) {
            pi = i;
        }
        if (q[i] > q[qi]) {
            qi = i;
        }
        if (p[pi] > q[qi] or (p[pi] == q[qi] and q[i - pi] > p[i - qi])) {
            cout << (ps[p[pi]] + ps[q[i - pi]]) % MOD << ' ';
        } else {
            cout << (ps[q[qi]] + ps[p[i - qi]]) % MOD << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preset();

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}