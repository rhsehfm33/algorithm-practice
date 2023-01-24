#include <bits/stdc++.h>

using namespace std;

void solve(int _ti) {
    int n;
    cin >> n;
    map<int, int> m;
    vector<array<int, 2>> ai_i(n);
    for (int i = 0; i < n; ++i) {
        cin >> ai_i[i][0];
        ai_i[i][1] = i;
        ++m[ai_i[i][0]];
    }
    for (auto& [ai, cnt] : m) {
        if (cnt > 2) {
            cout << "NO\n";
            return;
        }
    }

    multiset<int> can;
    for (int i = 1; i <= n; ++i) {
        can.insert(i);
        can.insert(i);
    }

    sort(ai_i.begin(), ai_i.end());
    map<int, int> p2q;
    vector<int> p(n), q(n);
    for (auto [ai, i] : ai_i) {
        if (m[ai] == 1) {
            if (can.count(ai) == 0) {
                cout << "NO\n";
                return;
            }
            can.erase(can.find(ai));
            if (can.count(ai) == 0) {
                cout << "NO\n";
                return;
            }
            can.erase(can.find(ai));
            p[i] = q[i] = ai;
        }
        else {
            if (p2q.count(ai)) {
                q[i] = ai;
                p[i] = p2q[ai];
            }
            else {
                if (*can.begin() >= ai) {
                    cout << "NO\n";
                    return;
                }
                p2q[ai] = *can.begin();
                p[i] = ai;
                q[i] = p2q[ai];
            }
            can.erase(ai);
            can.erase(p2q[ai]);
        }
    }

    cout << "YES\n";
    for (auto& pi : p) {
        cout << pi << ' ';
    }
    cout << '\n';
    for (auto& qi : q) {
        cout << qi << ' ';
    }
    cout << '\n';
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