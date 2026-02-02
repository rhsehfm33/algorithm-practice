#include <bits/stdc++.h>
using namespace std;

int _ti;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& ai : a) {
        cin >> ai;
    }
    for (auto& bi : b) {
        cin >> bi;
    }
    string s;
    cin >> s;
    vector<array<int, 2>> lr(k);
    for (int i = 0, bal = 0, l = 0, r = 0; i < k; ++i) {
        bal += (s[i] == 'L' ? -1 : 1);
        l = min(l, bal);
        r = max(r, bal);
        lr[i][0] = l;
        lr[i][1] = r;
    }

    sort(b.begin(), b.end());
    vector<int> die(k + 1);
    for (int i = 0; i < n; ++i) {
        int l = 0;
        int h = k - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            int mn = a[i] + lr[mid][0];
            int mx = a[i] + lr[mid][1];
            auto it = lower_bound(b.begin(), b.end(), mn);
            if (it != b.end() and *it <= mx) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ++die[h + 1];
    }

    for (int i = 0, alive = n; i < k; ++i) {
        alive -= die[i];
        cout << alive << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    for (_ti = 1; _ti <= T; ++_ti) {
        solve();
    }

    return 0;
}