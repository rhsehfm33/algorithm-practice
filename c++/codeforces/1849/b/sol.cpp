#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][0] = a[i][0] % k;
        a[i][0] = a[i][0] ? a[i][0] * -1 : -k;
        a[i][1] = i + 1;
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cout << a[i][1] << ' ';
    }
    cout << '\n';
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