#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> m;
    vector<array<int, 2>> a(n);
    for (auto& ai : a) {
        cin >> ai[1];
        ai[0] = m[ai[1]]++;
    }

    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        while (i + 1 < n and a[i][1] + 1 == a[i + 1][1]) {
            ++i;
        }
        ++ans;
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