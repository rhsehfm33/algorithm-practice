#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    vector<array<int, 2>> lr(n);
    for (auto& lri : lr) {
        cin >> lri[0] >> lri[1];
    }
    vector<array<int, 2>> xy(m);
    for (auto& xyi: xy) {
        cin >> xyi[0] >> xyi[1];
    }

    int ans = 0;
    priority_queue<int> pq;
    for (int i = 0, j = 0, k = 1; i < n; ++i) {
        while (j < m and xy[j][0] < lr[i][0]) {
            pq.push(xy[j][1]);
            ++j;
        }
        while (pq.size() and k < lr[i][1] - lr[i][0] + 2) {
            ++ans;
            k += pq.top();
            pq.pop();
        }
        if (k < lr[i][1] - lr[i][0] + 2) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
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