#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int p = 0, m = 1;

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= a[i - 1]) {
            ++p;
        }
    }
    
    int ans = p;
    for (int i = 1; i <= n; ++i) {
        if (i - 1 > 0 and a[i] >= a[i - 1]) {
            ++m;
        }
        if (i + 1 <= n and a[i] >= a[i + 1]) {
            --p;
        }
        ans = min(ans, m + p);
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