#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    int mx = a[0] + a[1];
    for (int i = 0; i + 1 < n; ++i) {
        mx = min(mx, a[i] + a[i + 1]);
    }

    cout << accumulate(a.begin(), a.end(), 0) + (mx * -2) << '\n';
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