#include <bits/stdc++.h>

using namespace std;

int _ti;

void solve() {
    int n;
    cin >> n;
    vector<int> p;
    vector<array<int, 2>> lr(n);
    map<int, vector<int>> l, r;
    for (int i = 0; i < n; ++i) {
        auto& [li, ri] = lr[i];
        cin >> li >> ri;
        l[li].push_back(i);
        r[ri].push_back(i);
        p.push_back(li);
        p.push_back(ri);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    vector<array<int, 2>> lrb(n);
    multiset<int> b;
    for (auto pi : p) {
        for (int lri : l[pi]) {
            b.insert(-lr[lri][0]);
        }
        sort(r[pi].begin(), r[pi].end(), [&](int i1, int i2) {
            return lr[i1][0] > lr[i2][0];
        });

        int plp = 0;
        for (int lri : r[pi]) {
            int lp = -lr[lri][0];
            b.erase(b.find(lp));
            if (lp != plp) {
                auto it = b.lower_bound(lp);
                lrb[lri][0] = it != b.end() ? -(*it) : 0;
                plp = lp;
            }
        }
    }

    b.clear();
    for (int i = p.size() - 1; i >= 0; --i) {
        int pi = p[i];
        for (int lri : r[pi]) {
            b.insert(lr[lri][1]);
        }
        sort(l[pi].begin(), l[pi].end(), [&](int i1, int i2) {
            return lr[i1][1] < lr[i2][1];
        });

        int prp = 0;
        for (int lri : l[pi]) {
            auto rp = lr[lri][1];
            b.erase(b.find(rp));
            if (rp != prp) {
                auto it = b.lower_bound(rp);
                lrb[lri][1] = it != b.end() ? *it : 0;
                prp = rp;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (lrb[i][0] and lrb[i][1]) {
            cout << lr[i][0] - lrb[i][0] + lrb[i][1] - lr[i][1] << '\n';
        } else {
            cout << "0\n";
        }
    }
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