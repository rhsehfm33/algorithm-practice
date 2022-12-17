#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

void solve(int _ti) {
    vector<pair<int, int>> xy(3);
    for (int i = 0; i < 3; ++i) {
        cin >> xy[i].fi >> xy[i].se;
    }

    for (int i = 0; i < 3; ++i) {
        if ((xy[(i + 1) % 3].fi == xy[i].fi and xy[(i + 2) % 3].se == xy[i].se) or
            (xy[(i + 1) % 3].se == xy[i].se and xy[(i + 2) % 3].fi == xy[i].fi)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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