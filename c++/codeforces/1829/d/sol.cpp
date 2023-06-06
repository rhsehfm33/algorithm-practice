#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;

    set<int> s;
    s.insert(n);
    queue<int> q;
    q.push(n);
    while (q.size()) {
        int cur = q.front(); q.pop();
        if (cur == m) {
            cout << "YES\n";
            return;
        }
        if (cur % 3 == 0) {
            if (s.count(cur / 3) == 0) {
                s.insert(cur / 3);
                q.push(cur / 3);
            }
            if (s.count(cur / 3 * 2) == 0) {
                s.insert(cur / 3 * 2);
                q.push(cur / 3 * 2);
            }
        }
    }

    cout << "NO\n";
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