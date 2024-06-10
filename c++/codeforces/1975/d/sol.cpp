#include <bits/stdc++.h>

using namespace std;

int _ti;

int getMid(vector<vector<int>>& v2v, vector<int>& vs, int cv, int pv, int b) {
    if (cv == b) {
        return vs.size() ? vs[vs.size() / 2] : b;
    }

    for (int nv : v2v[cv]) {
        if (nv != pv) {
            vs.push_back(cv);
            int mid = getMid(v2v, vs, nv, cv, b);
            if (mid != -1) {
                return mid;
            }
            vs.pop_back();
        }
    }
    return -1;
}

void go(vector<vector<int>>& v2v, int l, int cv, int pv, int b, int& mx, int& db) {
    if (cv == b) {
        db = l;
    }
    mx = max(mx, l);

    for (int nv : v2v[cv]) {
        if (nv != pv) {
            go(v2v, l + 1, nv, cv, b, mx, db);
        }
    }
}

void solve() {
    int n, a, b, mx = 0, db = 0, mb = 0;
    cin >> n >> a >> b;
    vector<int> vs;
    vector<vector<int>> v2v(n + 1);
    for (int i = 0, v1, v2; i < n - 1; ++i) {
        cin >> v1 >> v2;
        v2v[v1].push_back(v2);
        v2v[v2].push_back(v1);
    }

    int mid = getMid(v2v, vs, a, -1, b);
    go(v2v, 0, mid, -1, b, mx, db);

    cout << (n - 1) * 2 - mx + db << '\n';
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