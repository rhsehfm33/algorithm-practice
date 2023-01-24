#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    if (n % 2) {
        cout << "NO\n";
        return;
    }

    vector<int> ans(n);
    sort(a.begin(), a.end());
    for (int i = 0, l = 0, r = n / 2; i < n; i += 2) {
        ans[i] = a[l++];
        ans[i + 1] = a[r++];
    }

    for (int i = 0; i < n; ++i) {
        int l = (i - 1 + n) % n;
        int r = (i + 1) % n;
        if ((ans[i] < ans[l] and ans[i] < ans[r]) or
            (ans[i] > ans[l] and ans[i] > ans[r])) {
            continue;
        }
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
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