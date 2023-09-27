#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<array<int, 2>> se(n);
    for (int i = 0; i < n; ++i) {
        cin >> se[i][0] >> se[i][1];
    }

    for (int i = 1; i < n; ++i) {
        if (se[i][0] >= se[0][0] and se[i][1] >= se[0][1]) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << se[0][0] << '\n';
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