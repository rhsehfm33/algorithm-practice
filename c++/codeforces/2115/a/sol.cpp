#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int _ti;

void solve() {
    int n, gcd = 0;
    cin >> n;
    vector<int> a(n), m(5001, INF);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]] = 0;
        gcd = __gcd(gcd, a[i]);
    }

    while (m.size() - 1 != gcd) {
        if (m.back() == INF) {
            m.pop_back();
            continue;
        }

        int ck = m.size() - 1;
        int cv = m.back();
        m.pop_back();
        vector<int> nm = m;
        for (int i = 1; i < ck; ++i) {
            if (m[i] == INF) {
                continue;
            }
            int nk = __gcd(i, ck);
            int nv = m[i] + cv + 1;
            nm[nk] = min(nm[nk], nv);
        }
        m = nm;
    }

    int ans = max(0, m.back() - 1);
    for (auto ai : a) {
        if (ai != gcd) {
            ++ans;
        }
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