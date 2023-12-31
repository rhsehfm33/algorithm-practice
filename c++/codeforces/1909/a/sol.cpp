#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    int mnx = 200, mny = 200, mxx = -200, mxy = -200;
    while (n--) {
        int x, y;
        cin >> x >> y;
        mnx = min(mnx, x);
        mxx = max(mxx, x);
        mny = min(mny, y);
        mxy = max(mxy, y);
    }

    if (mnx * mxx >= 0 or mny * mxy >= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
    }

    return 0;
}