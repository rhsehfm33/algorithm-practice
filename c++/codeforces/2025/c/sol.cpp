#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());

    int ans = 0, sum = 0;
    map<int, int> m;
    for (int l = 0, r = 0; r < n; ++r) {
        if (r and a[r] > a[r - 1] + 1) {
            l = r;
            sum = 0;
            m.clear();
        }
        ++sum;
        ++m[a[r]];
        while (m.size() > k) {
            if (--m[a[l]] == 0) {
                m.erase(a[l]);
            }
            --sum;
            ++l;
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
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