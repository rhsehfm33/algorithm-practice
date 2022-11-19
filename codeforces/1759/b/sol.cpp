#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int m, sum;
    cin >> m >> sum;
    set<int> used;
    for (int i = 0; i < m; ++i) {
        int bi;
        cin >> bi;
        used.insert(bi);
    }

    for (int i = 1; i <= 100 and (sum > 0 or used.size()); ++i) {
        if (used.count(i)) {
            used.erase(i);
            continue;
        }
        sum -= i;
    }

    if (used.size() == 0 and sum == 0) {
        cout << "YES\n";
    }
    else {
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