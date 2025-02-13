#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n, k, l;
    cin >> n >> k >> l;
    k *= 2, l *= 2;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ai *= 2;
    }

    int t = a[0];
    int d = k;
    for (int i = 1; i < n and d < l; ++i) {
        if (d < a[i] - t) {
            int at = (a[i] - t - d) / 2;
            t += at;
            d += at;
        }
        d = min(d + k, a[i] + t + k);
    }
    t += d < l ? l - d : 0;
    cout << t << '\n';
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