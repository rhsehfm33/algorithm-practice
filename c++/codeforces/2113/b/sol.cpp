#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int w, h, a, b, x1, y1, x2, y2;
    cin >> w >> h >> a >> b >> x1 >> y1 >> x2 >> y2;
    int ax1 = (x1 + a) % a;
    int ax2 = (x2 + a) % a;
    int by1 = (y1 + b) % b;
    int by2 = (y2 + b) % b;
    if ((ax1 == ax2 and x1 != x2)
    or  (by1 == by2 and y1 != y2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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