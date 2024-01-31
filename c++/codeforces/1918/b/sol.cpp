#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<array<int, 2>> ab(n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ab[j][i];
        }
    }
    sort(ab.begin(), ab.end());

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ab[j][i] << ' ';
        }
        cout << '\n';
    }
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