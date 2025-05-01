#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

int _ti;

void solve() {
    map<int, int> xc, dc;
    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        ++xc[x];
        ++dc[x + y];
    }

    int ax, ay;
    for (auto& [x, c] : xc) {
        if (c & 1) {
            ax = x;
            break;
        }
    }
    for (auto& [x, c] : dc) {
        if (c & 1) {
            ay = x - ax;
            break;
        }
    }
    cout << ax << ' ' << ay << '\n';
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