#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    queue<array<int, 2>> q[2];
    for (int x = 1; q[0].size() < n; x += 3) {
        for (int x2 = x, y = 1; x2 >= 1; x2 -= 3, y += 3) {
            q[0].push({x2, y});
        }
    }
    for (int x = 1; q[1].size() < n; ++x) {
        for (int x2 = x, y = 1; x2 >= 1; --x2, ++y) {
            if (y % 3 == 1 and x % 3) {
                q[1].push({x2, y});
            } else if (y % 3 == 2 and x2 % 3 == 1) {
                if (x2 - 2 >= 1) {
                    q[1].push({x2 - 2, y});
                }
                q[1].push({x2, y});
            }
        }
    }

    set<array<int, 2>> s;
    while (n--) {
        int ti;
        cin >> ti;
        while (s.count(q[ti].front())) {
            q[ti].pop();
        }
        auto [x, y] = q[ti].front();
        cout << y << ' ' << x << '\n';
        s.insert({x, y});
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