#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 2 == 0) {
        cout << "0\n";
        return;
    }

    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        int ai = a[i];
        while ((ai + a[i]) % 2 == 0) {
            ai /= 2;
            cnt += 1;
        }
        ans = min(ans, cnt);
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