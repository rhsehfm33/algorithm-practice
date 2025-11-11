#include <bits/stdc++.h>
using namespace std;

int _ti;

int ask(int i, int x) {
    int in;
    cout << "? " << i << ' ' << x << endl;
    cin >> in;
    return in;
}

void solve() {
    int i = 0;
    int n;
    cin >> n;
    vector<int> p(n), q(n - 1);
    iota(p.begin(), p.end(), 1);
    iota(q.begin(), q.end(), 1);
    while (p.size() > 1) {
        array<int, 2> c = {0, 0};
        for (auto& pi : p) {
            ++c[(pi >> i) & 1];
        }

        vector<vector<int>> ca(2);
        for (auto& qi : q) {
            ca[ask(qi, (1 << i))].push_back(qi);
        }

        int t = ca[1].size() != c[1];
        q = ca[t];

        vector<int> np;
        for (auto& pi : p) {
            if (((pi >> i) & 1) == t) {
                np.push_back(pi);
            }
        }
        p = np;
        ++i;
    }
    cout << "! " << p[0] << endl;
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