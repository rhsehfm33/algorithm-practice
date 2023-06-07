#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<array<int, 2>> ab(n);
    for (int i = 0; i < n; ++i) {
        cin >> ab[i][0] >> ab[i][1];
    }

    sort(ab.begin(), ab.end(), [](auto& l, auto& r) {
        if (l[0] != r[0]) {
            return l[0] < r[0];
        }
        else {
            return l[1] > r[1];
        }
    });

    ll ans = 0;
    queue<int> q;
    for (int i = 0, cnt = 0; i < n; ++i) {
        if (ab[i][0] <= cnt) {
            continue;
        }

        ans += ab[i][1];
        q.push(ab[i][0]);
        cnt = max(cnt, (int)q.size());
        while (q.size() and q.front() <= cnt) {
            q.pop();
        }
    }

    cout << ans << '\n';
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