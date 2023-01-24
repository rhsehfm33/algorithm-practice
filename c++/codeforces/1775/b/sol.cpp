#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> d2s;
    vector<vector<int>> p(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int d;
            cin >> d;
            p[i].push_back(d);
            ++d2s[d];
        }
    }

    for (auto& ds : p) {
        bool is_all_dup = true;
        for (auto& d : ds) {
            if (d2s[d] == 1) {
                is_all_dup = false;
                break;
            }
        }
        if (is_all_dup) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    return;
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