#include <bits/stdc++.h>

using namespace std;

const int INIT = -1;

void solve(int _ti) {
    int m;
    string s, l, r;
    cin >> s >> m >> l >> r;

    vector<queue<int>> indexes(10);
    for (int i = 0; i < s.size(); ++i) {
        indexes[s[i] - '0'].push(i);
    }

    for (int i = 0; i < m; ++i) {
        int maxIndex = INIT;
        for (int j = l[i] - '0'; j <= r[i] - '0'; ++j) {
            if (indexes[j].empty()) {
                cout << "YES" << '\n';
                return;
            }
            maxIndex = max(maxIndex, indexes[j].front());
        }

        for (int j = 0; j <= 9; ++j) {
            while (indexes[j].size() and indexes[j].front() <= maxIndex) {
                indexes[j].pop();
            }
        }
    }

    cout << "NO" << '\n';
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