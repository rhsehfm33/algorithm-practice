#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[0]) {
            continue;
        }
        a[0] += (a[i] - a[0]) / 2 + (a[i] - a[0]) % 2;
    }

    cout << a[0] << '\n';
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