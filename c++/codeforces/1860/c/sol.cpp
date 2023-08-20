#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
    }

    int ans = 0;
    for (int i = 0, aw = 1e9, bw = 1e9; i < p.size(); ++i) {
        if (aw < p[i] or bw > p[i]) {
            bw = min(bw, p[i]);
        }
        else {
            aw = min(aw, p[i]);
            ++ans;
        }
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