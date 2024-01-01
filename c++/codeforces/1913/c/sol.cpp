#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<int> pc(30), pv(30);
    for (int i = 0; i < 30; ++i) {
        pv[i] = 1 << i;
    }

    while (m--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            ++pc[v];
        } else {
            for (int i = 29; i >= 0 and v != 0; --i) {
                if (pv[i] <= v) {
                    v -= min(pc[i], v / pv[i]) * pv[i];
                }
            }
            cout << (v == 0 ? "YES\n" : "NO\n");
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}