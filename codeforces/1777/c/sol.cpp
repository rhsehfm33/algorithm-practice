#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve(int _ti) {
    int n, m;
    cin >> n >> m;
    set<int> ai_set;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        ai_set.insert(ai);
    }
    sort(a.begin(), a.end());

    map<int, vector<int>> ai2t;
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= a.back(); j += i) {
            if (ai_set.count(j)) {
                ai2t[j].push_back(i);
            }
        }
    }

    int ans = INF;
    map<int, int> t2cnt;
    for (int l = 0, r = 0; l < n; ++l) {
        while (r < n and t2cnt.size() < m) {
            for (auto t : ai2t[a[r]]) {
                ++t2cnt[t];
            }
            ++r;
        }

        if (t2cnt.size() == m) {
            if (r == l) {
                cout << "0\n";
                return;
            }
            ans = min(ans, a[r - 1] - a[l]);
        }

        for (auto t : ai2t[a[l]]) {
            if ((--t2cnt[t]) == 0) {
                t2cnt.erase(t);
            }
        }
    }

    if (ans == INF) {
        ans = -1;
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