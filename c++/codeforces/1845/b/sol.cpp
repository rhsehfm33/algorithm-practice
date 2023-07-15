#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int ans = 0;
    if ((xb <= xa and xc <= xa) or (xb >= xa and xc >= xa)) {
        ans += min(abs(xb - xa), abs(xc - xa));
    }
    if ((yb <= ya and yc <= ya) or (yb >= ya and yc >= ya)) {
        ans += min(abs(yb - ya), abs(yc - ya));
    }

    cout << ans + 1 << '\n';
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