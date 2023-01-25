#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    if (a1 == 0) {
        cout << 1 << '\n';
        return;
    }

    int smaller = a1 - abs(a2 - a3);
    if (smaller <= 0) {
        cout << min(a1 + a2 + a3 + a4, a1 + a2 + a3 + smaller + 1) << '\n';
        return;
    }

    cout << a1 + a2 + a3 + min(smaller + 1, a4) << '\n';
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