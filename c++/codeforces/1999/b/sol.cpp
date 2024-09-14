#include <bits/stdc++.h>

using namespace std;

int _ti;

int cal(int a, int b) {
    return (a > b ? 1 : (a < b ? -1 : 0));
}

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int w1 = (cal(a1, b1) + cal(a2, b2) > 0);
    int w2 = (cal(a2, b1) + cal(a1, b2) > 0);
    cout << (w1 + w2) * 2 << '\n';
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