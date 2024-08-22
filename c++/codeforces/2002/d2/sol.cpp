#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int _ti;

void setP(vvi& u2v, vvi& p, vi& l, int pu, int u) {
    p[u].push_back(pu);
    l[u] = l[pu] + 1;

    int i = 1;
    while (p[pu].size() >= i) {
        p[u].push_back(p[pu][i - 1]);
        pu = p[pu][i - 1];
        ++i;
    }

    for (int v : u2v[u]) {
        setP(u2v, p, l, u, v);
    }
}

void updateMatch(vb& match, int i, bool b, int& k) {
    if (match[i] != b) {
        match[i] = b;
        k += (b ? 1 : -1);
    }
}

void checkParent(vvi& u2v, vvi& p, vb& match, vi& l, int per1, int per2, int& k) {
    if (p[per2][0] == per1) {
        updateMatch(match, per2, true, k);
    } else if (u2v[per1].size()) {
        updateMatch(match, per2, false, k);
    } else {
        int dif = l[per1] - (l[per2] - 1);
        int i = dif <= 0 ? -1 : log2(dif);
        while (i >= 0) {
            if ((dif & (1 << i)) and p[per1].size() > i) {
                dif -= (1 << i);
                per1 = p[per1][i];
            }
            --i;
        }

        updateMatch(match, per2, (dif == 0 and per1 == p[per2][0]), k);
    }
}

void solve() {
    int n, q, k = 0;
    cin >> n >> q;
    vector<bool> match(n + 1);
    vector<int> l(n + 1), pers(n + 1);
    vector<vector<int>> u2v(n + 1), p(n + 1);
    for (int i = 2; i <= n; ++i) {
        int ai; cin >> ai;
        u2v[ai].push_back(i);
    }
    setP(u2v, p, l, 0, 1);

    for (int i = 1; i <= n; ++i) {
        cin >> pers[i];
    }
    for (int i = 1; i <= n; ++i) {
        checkParent(u2v, p, match, l, pers[i - 1], pers[i], k);
    }

    while (q--) {
        int x, y; cin >> x >> y;
        swap(pers[x], pers[y]);

        checkParent(u2v, p, match, l, pers[x - 1], pers[x], k);
        if (x + 1 <= n) {
            checkParent(u2v, p, match, l, pers[x], pers[x + 1], k);
        }
        checkParent(u2v, p, match, l, pers[y - 1], pers[y], k);
        if (y + 1 <= n) {
            checkParent(u2v, p, match, l, pers[y], pers[y + 1], k);
        }

        if (k == n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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