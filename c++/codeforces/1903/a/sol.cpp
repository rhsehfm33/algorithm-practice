#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    bool s = true;
    int n, k;
    cin >> n >> k;
    for (int i = 0, prv = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if (ai < prv) {
            s = false;
        }
        prv = ai;
    }

    if (k == 1 and s == false) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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