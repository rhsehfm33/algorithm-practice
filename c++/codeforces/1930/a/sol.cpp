#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (auto& ai : a) {
        cin >> ai;
    }

    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n * 2; i += 2) {
        ans += a[i];
    }
    cout << ans << '\n';
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