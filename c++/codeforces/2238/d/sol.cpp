#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;

    int pc = 0, fc = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i) {
            continue;
        }
        ++pc;
        while (n % i == 0) {
            n /= i;
            ++fc;
        }
    }
    if (n > 1) {
        ++pc;
        ++fc;
    }
    cout << (pc + fc - 1) << '\n';
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