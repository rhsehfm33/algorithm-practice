#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m, d;
    cin >> n >> m >> d;

    map<int, int> pi2i;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pi2i[--p[i]] = i;
    }
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }

    int mx = 1e9;
    for (int i = 0; i + 1 < m; ++i) {
        int pos1 = pi2i[a[i]];
        int pos2 = pi2i[a[i + 1]];
        if (pos1 >= pos2 or pos2 > pos1 + d) {
            cout << "0\n";
            return;
        }
        int diff = pos2 - pos1;
        mx = min(mx, diff);
        mx = d < n - 1 ? min(mx, d + 1 - diff) : mx;
    }

    cout << mx << '\n';
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