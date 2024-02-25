#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> as, bs, abs;
    while (n--) {
        int ai;
        cin >> ai;
        if (ai >= 1 and ai <= k) {
            as.insert(ai);
            abs.insert(ai);
        }
    }
    while (m--) {
        int bi;
        cin >> bi;
        if (bi >= 1 and bi <= k) {
            bs.insert(bi);
            abs.insert(bi);
        }
    }

    if (abs.size() >= k and as.size() >= k / 2 and bs.size() >= k / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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