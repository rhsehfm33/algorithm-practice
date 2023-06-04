#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int x, k;
    cin >> x >> k;
    if (x % k) {
        cout << 1 << '\n' << x << '\n';
    }
    else {
        cout << 2 << '\n' << x - 1 << ' ' << 1 << '\n';
    }
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