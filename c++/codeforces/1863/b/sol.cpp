#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0];
        p[i][1] = i;
    }

    int ans = 0;
    sort(p.begin(), p.end());
    for (int i = 1; i < n; ++i) {
        if (p[i][1] < p[i - 1][1]) {
            ++ans;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (int ti = 1; ti <= T; ++ti) {
        solve(ti);
        cout << '\n';
    }

    return 0;
}