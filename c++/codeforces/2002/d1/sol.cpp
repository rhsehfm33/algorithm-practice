#include <bits/stdc++.h>
 
using namespace std;
 
int _ti;
 
void updateFit(int& fc, vector<bool>& fits, vector<int>& p, int pi, int n) {
    int after = 1;
    int cur = p[pi];
    while (cur <= n) {
        cur *= 2;
        after *= 2;
    }
 
    if ((pi - 1 >= 0 and p[pi - 1] == p[pi] / 2) or
    (pi - after >= 0 and p[pi - after] == p[pi] / 2)) {
        if (!fits[p[pi]]) {
            fits[p[pi]] = true;
            ++fc;
        }
    } else {
        if (fits[p[pi]]) {
            fits[p[pi]] = false;
            --fc;
        }
    }
}
 
void updateAllFit(map<int, int>& m, int& fc, vector<bool>& fits, vector<int>& p, int pi, int n) {
    updateFit(fc, fits, p, pi, n);
    if (p[pi] * 2 <= n) {
        updateFit(fc, fits, p, m[p[pi] * 2], n);
        updateFit(fc, fits, p, m[p[pi] * 2 + 1], n);
    }
}
 
void solve() {
    map<int, int> m;
    int n, q, fc = 0;
    cin >> n >> q;
    vector<bool> fits(n + 1);
    vector<int> a(n + 1), p(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        m[p[i]] = i;
    }
 
    for (int i = 1; i <= n; ++i) {
        updateFit(fc, fits, p, i, n);
    }
 
    while (q--) {
        int x, y;
        cin >> x >> y;
        swap(p[x], p[y]);
        m[p[x]] = x;
        m[p[y]] = y;
        updateAllFit(m, fc, fits, p, x, n);
        updateAllFit(m, fc, fits, p, y, n);
        if (fc == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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