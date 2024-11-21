#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    if (n <= 4) {
        cout << -1 << '\n';
        return;
    }
    list<int> l = {5, 4};
    for (int i = 1; i <= n; ++i) {
        if (i == 5 or i == 4) {
            continue;
        }
        if (i % 2) {
            l.push_front(i);
        } else {
            l.push_back(i);
        }
    }

    for (auto li : l) {
        cout << li << ' ';
    }
    cout << '\n';
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