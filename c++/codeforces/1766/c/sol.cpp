#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<string>& c, int x, int y) {
    if (y == c[0].size() - 1) {
        return true;
    }

    if (c[x][y + 1] == 'B') {
        if (c[x ^ 1][y + 1] == 'B') {
            return is_possible(c, x ^ 1, y + 1);
        }
        else {
            return is_possible(c, x, y + 1);
        }
    }

    return false;
}

void solve(int _ti) {
    int m;
    cin >> m;
    vector<string> c(2);
    cin >> c[0] >> c[1];

    if ((c[0][0] == 'B' and is_possible(c, 0, 0)) or
        (c[1][0] == 'B' and is_possible(c, 1, 0))) {
        cout << "YES\n";
    }
    else {
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