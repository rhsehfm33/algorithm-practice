#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, x;
    cin >> n >> x;
    vector<queue<int>> qs(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            qs[i].push(b);
        }
    }

    int cur = 0;
    while (true) {
        bool isPoped = false;
        for (int i = 0; i < 3; ++i) {
            if (qs[i].size() and (x | qs[i].front()) == x) {
                cur |= qs[i].front();
                qs[i].pop();
                isPoped = true;
            }
        }
        if (isPoped == false) {
            break;
        }
    }

    if (cur == x) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
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