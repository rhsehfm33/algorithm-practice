#include <bits/stdc++.h>

using namespace std;

void mp(int h, int w, int& y1, int& y2, bool is1Win) {
    if (is1Win) {
        if (y1 < y2 and y1 + 1 <= w) {
            ++y1;
        } else if (y1 > y2 and y1 - 1 >= 1) {
            --y1;
        }
    } else {
        if (y1 < y2 and y1 - 1 >= 1) {
            --y1;
        } else if (y1 > y2 and y1 + 1 <= w) {
            ++y1;
        }
    }
}

void solve(int _ti) {
    int h, w, x1, y1, x2, y2;
    cin >> h >> w >> x1 >> y1 >> x2 >> y2;

    bool aw = (x2 - x1) % 2;
    string ans = "Draw";
    for (int i = 0; i < h and x1 < x2; ++i) {
        mp(h, w, y1, y2, aw);
        ++x1;
        if (x1 == x2 and y1 == y2) {
            ans = "Alice";
        }

        mp(h, w, y2, y1, !aw);
        --x2;
        if (x1 == x2 and y1 == y2) {
            ans = "Bob";
        }
    }

    cout << ans << '\n';
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